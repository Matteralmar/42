/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:51:09 by gvasylie          #+#    #+#             */
/*   Updated: 2025/09/15 12:51:43 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "printf/ft_printf.h"

void	handle_signal(int signal, siginfo_t *inf, void *context)
{
	static unsigned char	chr;
	static int				b_ind;

	(void)context;
	chr |= (signal == SIGUSR1);
	b_ind++;
	if (b_ind == 8)
	{
		if (chr == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", chr);
		b_ind = 0;
		chr = 0;
	}
	else
		chr <<= 1;
	if (signal == SIGUSR1)
		kill(inf->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(inf->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
