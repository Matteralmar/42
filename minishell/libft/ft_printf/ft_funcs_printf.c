/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaligula <kaligula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:03:42 by vivantso          #+#    #+#             */
/*   Updated: 2025/10/25 10:09:19 by kaligula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr(char *s, int fd)
{
	int	count;

	if (!s)
		s = "(null)";
	count = 0;
	while (*s)
		count += ft_putchar(*s++, fd);
	return (count);
}

int	ft_putnbr(int n, int fd)
{
	long	num;
	int		count;

	num = n;
	count = 0;
	if (num < 0)
	{
		count += ft_putchar('-', fd);
		num = -num;
	}
	if (num > 9)
		count += ft_putnbr(num / 10, fd);
	count += ft_putchar(num % 10 + '0', fd);
	return (count);
}

int	ft_putnbr_base(unsigned long nbr, char *base, int fd)
{
	int	len_base;
	int	count;

	len_base = 0;
	count = 0;
	while (base[len_base])
		len_base++;
	if (nbr >= (unsigned long)len_base)
		count += ft_putnbr_base(nbr / len_base, base, fd);
	count += ft_putchar(base[nbr % len_base], fd);
	return (count);
}

int	ft_format(char spec, va_list *args, char **bases, int fd)
{
	unsigned long	ptr;

	if (spec == 'c')
		return (ft_putchar(va_arg(*args, int), fd));
	else if (spec == 's')
		return (ft_putstr(va_arg(*args, char *), fd));
	else if (spec == 'p')
	{
		ptr = va_arg(*args, unsigned long);
		if (!ptr)
			return (ft_putstr("(nil)", fd));
		return (ft_putstr("0x", fd) + ft_putnbr_base((unsigned long)ptr,
				bases[1], fd));
	}
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*args, int), fd));
	else if (spec == 'u')
		return (ft_putnbr_base(va_arg(*args, unsigned int), bases[0], fd));
	else if (spec == 'x')
		return (ft_putnbr_base(va_arg(*args, unsigned int), bases[1], fd));
	else if (spec == 'X')
		return (ft_putnbr_base(va_arg(*args, unsigned int), bases[2], fd));
	else if (spec == '%')
		return (ft_putchar('%', fd));
	return (0);
}
