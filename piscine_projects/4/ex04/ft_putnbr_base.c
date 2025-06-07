/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:44:48 by gvasylie          #+#    #+#             */
/*   Updated: 2025/04/28 12:45:24 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <unistd.h>

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		base_len;

	base_len = is_valid_base(base);
	nb = nbr;
	if (base_len < 2)
		return ;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base);
	ft_putchar(base[nb % base_len]);
}

// int main()
// {
//     ft_putnbr_base(42, "0123456789");     // prints "42"
//     write(1, "\n", 1);
//     ft_putnbr_base(-42, "0123456789");    // prints "-42"
//     write(1, "\n", 1);
//     ft_putnbr_base(255, "01");            // prints "11111111"
//     write(1, "\n", 1);
//     ft_putnbr_base(255, "0123456789ABCDEF"); // prints "FF"
//     write(1, "\n", 1);
//     ft_putnbr_base(64, "poneyvif");       // prints "ey"
//     write(1, "\n", 1);
//     ft_putnbr_base(42, "");               // invalid, prints nothing
//     write(1, "\n", 1);
//     ft_putnbr_base(42, "0");              // invalid, prints nothing
//     write(1, "\n", 1);
//     ft_putnbr_base(42, "012+3456789");    // invalid, prints nothing
//     write(1, "\n", 1);
// }