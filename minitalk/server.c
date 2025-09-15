/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:51:13 by gvasylie          #+#    #+#             */
/*   Updated: 2025/09/15 12:51:44 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "printf/ft_printf.h"

void	handle_signal(int signal)
{
	static unsigned char	chr;
	static int				b_ind;

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
}

int	main(void)
{
	printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
