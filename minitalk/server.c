/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 15:00:59 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/01 14:12:14 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

static void	take_signal(int sig);

int	main(void)
{
	pid_t	pid;
	size_t	len;
	char	*pid_str;

	pid = getpid();
	pid_str = ft_itoa(pid);
	if (!pid_str)
		return (1);
	len = ft_strlen(pid_str);
	write(1, pid_str, len);
	write(1, "\n", 1);
	free(pid_str);
	signal(SIGUSR1, take_signal);
	signal(SIGUSR2, take_signal);
	while (1)
		pause();
	return (0);
}

static void	take_signal(int sig)
{
	static int				bit_position;
	static unsigned char	letter;

	if (sig == SIGUSR1)
		letter |= (1 << bit_position);
	if (++bit_position == 8)
	{
		bit_position = 0;
		if (letter != '\0')
			write(1, &letter, 1);
		else
			write(1, "\n", 1);
		letter = 0;
	}
}
