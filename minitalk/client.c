/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:35:00 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/01 14:12:00 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

static void	send_signal(char letter, int bit_position, int pid);

int	main(int argc, char **argv)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
			send_signal(argv[2][i++], 0, pid);
		send_signal('\0', 0, pid);
	}
	else
	{
		write(1, "Error: [Usage: ./client <pid> <message>]\n", 42);
		return (1);
	}
	return (0);
}

static void	send_signal(char letter, int bit_position, int pid)
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
