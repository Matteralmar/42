/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaligula <kaligula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:35:08 by vivantso          #+#    #+#             */
/*   Updated: 2025/10/25 10:08:18 by kaligula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;
	char	*bases[3];

	bases[0] = "0123456789";
	bases[1] = "0123456789abcdef";
	bases[2] = "0123456789ABCDEF";
	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			printed += ft_format(format[i], &args, bases, 1);
		}
		else
			printed += ft_putchar(format[i], 1);
		i++;
	}
	va_end(args);
	return (printed);
}

int	ft_dprintf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed;
	char	*bases[3];

	bases[0] = "0123456789";
	bases[1] = "0123456789abcdef";
	bases[2] = "0123456789ABCDEF";
	i = 0;
	printed = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			printed += ft_format(format[i], &args, bases, 2);
		}
		else
			printed += ft_putchar(format[i], 2);
		i++;
	}
	va_end(args);
	return (printed);
}
