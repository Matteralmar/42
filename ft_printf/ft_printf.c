/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 15:01:11 by gvasylie          #+#    #+#             */
/*   Updated: 2025/06/07 15:01:11 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid(char c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'p' || c == '%');
}

static size_t	flag_cond(char c, va_list args)
{
	if (c == 'c')
		return (pr_chr(va_arg(args, int)));
	else if (c == 's')
		return (pr_str(va_arg(args, char *)));
	else if (c == 'd' || c == 'i')
		return (pr_numb(va_arg(args, int)));
	else if (c == 'u')
		return (pr_unumb(va_arg(args, unsigned int)));
	else if (c == 'p')
		return (pr_ptr(va_arg(args, void *)));
	else if (c == 'x')
		return (pr_hex(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (pr_hex(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (pr_chr('%'));
	return (0);
}

size_t	next_cond(char c, va_list args)
{
	size_t	len;

	len = 0;
	if (is_valid(c))
		len += flag_cond(c, args);
	else
	{
		len += pr_chr('%');
		len += pr_chr(c);
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	flags;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	va_start(flags, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
			{
				va_end(flags);
				return (-1);
			}
			len += next_cond(format[i], flags);
			i++;
		}
		else
			len += pr_chr(format[i++]);
	}
	va_end(flags);
	return ((int)len);
}

