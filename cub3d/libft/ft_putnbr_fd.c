/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:16:09 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/19 16:56:56 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	if (i >= 0 && i < 10)
	{
		ft_putchar_fd(i + '0', fd);
	}
	else if (i == -2147483648)
	{
		write (fd, "-2147483648", 11);
	}
	else if (i < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(i * (-1), fd);
	}
	else
	{
		ft_putnbr_fd(i / 10, fd);
		ft_putnbr_fd(i % 10, fd);
	}
}
/* int	main(void)
{
	int	i = 12;
	int fd = 2;
	printf("%d", ft_putnbr_fd(i, fd));
	return (0);
} */
