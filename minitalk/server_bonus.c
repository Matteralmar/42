/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:53:48 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/01 14:10:51 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

static void	take_signal(int sig, siginfo_t *pid, void *none);

int	main(void)
{
	pid_t				pid;
	size_t				len;
	char				*pid_str;
	struct sigaction	sig_strct;

	pid = getpid();
	pid_str = ft_itoa(pid);
	if (!pid_str)
		return (1);
	len = ft_strlen(pid_str);
	write(1, pid_str, len);
	write(1, "\n", 1);
	free(pid_str);
	sig_strct.sa_sigaction = &take_signal;
	sig_strct.sa_flags = SA_SIGINFO;
	sigemptyset(&sig_strct.sa_mask);
	sigaction(SIGUSR1, &sig_strct, NULL);
	sigaction(SIGUSR2, &sig_strct, NULL);
	while (1)
		pause();
	return (0);
}

static void	take_signal(int sig, siginfo_t *pid, void *none)
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
	if (sig == SIGUSR1)
		kill(pid->si_pid, SIGUSR1);
	else if (sig == SIGUSR2)
		kill(pid->si_pid, SIGUSR2);
}
