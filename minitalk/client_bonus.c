/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 17:58:22 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/01 14:08:28 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

static void	send_char(char letter, int bit_position, int pid);
static void	take_signal(int sig);

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (argc == 3)
	{
		signal(SIGUSR1, take_signal);
		signal(SIGUSR2, take_signal);
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
			send_char(argv[2][i++], 0, pid);
		send_char('\0', 0, pid);
	}
	else
	{
		write(1, "Error: [Usage: ./client <pid> <message>]\n", 42);
		return (1);
	}
	return (0);
}

static void	send_char(char letter, int bit_position, int pid)
{
	while (bit_position < 8)
	{
		if (letter & (1 << bit_position))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit_position++;
	}
}

static void	take_signal(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Current bit 1\n", 15);
	else if (sig == SIGUSR2)
		write(1, "Current bit 0\n", 15);
}
