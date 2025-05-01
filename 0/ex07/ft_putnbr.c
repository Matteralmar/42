/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 12:06:54 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/24 12:17:41 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_c(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-2147483648", 11);
			return ;
		}
		write_c('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	write_c(nb % 10 + '0');
}

/*
int	main(void)
{
	ft_putnbr(-2147483648);
	return (0);
}
*/