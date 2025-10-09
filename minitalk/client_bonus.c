/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 10:09:26 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/06 10:09:26 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signals(unsigned int len, pid_t pid, int bits)
{
	int	bit_position;

	bit_position = 0;
	while (bit_position < bits)
	{
		if (len & (1 << bit_position))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit_position++;
	}
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Current bit 1\n", 15);
	else
		write(1, "Current bit 0\n", 15);
}

int	main(int ac, char **av)
{
	pid_t			pid;
	char			*message;
	unsigned int	i;
	unsigned int	len;

	if (ac != 3)
		return (write(1, "Error: [Usage: ./client_bonus <pid> <message>]\n",
				48), 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	i = 0;
	pid = ft_atoi(av[1]);
	message = av[2];
	len = ft_strlen(message);
	send_signals(len, pid, 32);
	while (av[2][i])
		send_signals((unsigned char) av[2][i++], pid, 8);
	send_signals(0, pid, 8);
	return (0);
}
