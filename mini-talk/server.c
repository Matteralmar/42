/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:09:50 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/06 10:09:53 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_inf	g_inf;

void	reset_data(void)
{
	write(1, g_inf.str, g_inf.len);
	write(1, "\n", 1);
	free(g_inf.str);
	g_inf.str = NULL;
	g_inf.len = 0;
	g_inf.bit_pos1 = 0;
	g_inf.bit_pos2 = 0;
	g_inf.letter = 0;
	g_inf.i = 0;
}

void	handle_char(int sig)
{
	if (sig == SIGUSR1)
		g_inf.letter |= (1 << g_inf.bit_pos2);
	g_inf.bit_pos2++;
	if (g_inf.bit_pos2 >= 8)
	{
		if (g_inf.letter)
			g_inf.str[g_inf.i++] = g_inf.letter;
		else
		{
			g_inf.str[g_inf.i] = '\0';
			reset_data();
			return ;
		}
		g_inf.letter = 0;
		g_inf.bit_pos2 = 0;
	}
}

void	handle_len(int sig)
{
	if (g_inf.bit_pos1 < 32)
	{
		if (sig == SIGUSR1)
			g_inf.len |= (1 << g_inf.bit_pos1);
		g_inf.bit_pos1++;
		if (g_inf.bit_pos1 == 32)
		{
			g_inf.str = malloc(g_inf.len + 1);
			if (!g_inf.str)
				exit(1);
			g_inf.bit_pos2 = 0;
			g_inf.i = 0;
		}
	}
	else
		handle_char(sig);
}

int	main(void)
{
	pid_t	pid;
	char	*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	if (!pid_str)
		return (1);
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\n", 1);
	free(pid_str);
	signal(SIGUSR1, handle_len);
	signal(SIGUSR2, handle_len);
	while (1)
		pause();
	return (0);
}
