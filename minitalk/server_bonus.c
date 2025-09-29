/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:53:48 by gvasylie          #+#    #+#             */
/*   Updated: 2025/09/29 11:20:58 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

void	take_signal(int sig, siginfo_t *pid, void *none)
{
	static unsigned char	letter;
	static int				bit_position;

	if (sig == SIGUSR1)
		letter |= (1 << bit_position);
	bit_position++;
	if (bit_position == 8)
	{
		if (letter != '\0')
			write(1, &letter, 1);
		else
			write(1, "\n", 1);
		bit_position = 0;
		letter = 0;
	}
	if (sig == SIGUSR1)
		kill(pid->si_pid, SIGUSR1);
	else if (sig == SIGUSR2)
		kill(pid->si_pid, SIGUSR2);
}

int	main(void)
{
	pid_t				pid;
	size_t				len;
	char				*pid_str;
	struct sigaction	sig_strct;

	sig_strct.sa_sigaction = &take_signal;
	sig_strct.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_strct.sa_mask);
	pid = getpid();
	pid_str = ft_itoa(pid);
	if (!pid_str)
		return (1);
	len = ft_strlen(pid_str);
	write(1, pid_str, len);
	write(1, "\n", 1);
	free(pid_str);
	sigaction(SIGUSR1, &sig_strct, NULL);
	sigaction(SIGUSR2, &sig_strct, NULL);
	while (1)
		pause();
	return (0);
}
