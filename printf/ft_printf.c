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

int main()
{
	char *p;
	p = NULL;
	printf("============/Test c/============\n");

	printf(" %d\n", ft_printf("ft_printf character ' ':%c", ' '));
	printf(" %d\n", printf("printf character ' ':%c", ' ') + 3);

	printf(" %d\n", ft_printf("ft_printf character not printable:%c", 1));
	printf(" %d\n", printf("printf character not printable:%c", 1) + 3);

	printf(" %d\n", ft_printf("ft_printf character out of bounds minus:%c", -131));
	printf(" %d\n", printf("printf character out of bounds minus:%c", -131) + 3);

	printf(" %d\n", ft_printf("ft_printf character out of bounds plus:%c", 342));
	printf(" %d\n", printf("printf character out of bounds plus:%c", 342) + 3);

	printf(" %d\n", ft_printf("ft_printf nothing:%c"));
	printf(" %d\n", printf("printf nothing:%c") + 3);

	printf(" %d\n", ft_printf("ft_printf print string:%c", "abc"));
	printf(" %d\n", printf("printf print string:%c", "abc") + 3);

	printf(" %d\n", ft_printf("ft_printf print null terminator:%c", '\0'));
	printf(" %d\n", printf("printf print null terminator:%c", '\0') + 3);

	printf(" %d\n", ft_printf("ft_printf mixing flags:%%%c%c", '%'));
	printf(" %d\n", printf("printf mixing flags:%%%c%c", '%') + 3);

	printf("============/Test %%/============\n");

	printf(" %d\n", ft_printf("ft_printf:%%"));
	printf(" %d\n", printf("printf:%%") + 3);

	printf(" %d\n", ft_printf("ft_printf %% 3 times:%%%%%%"));
	printf(" %d\n", printf("printf %% 3 times:%%%%%%") + 3);

	printf(" %d\n", ft_printf("ft_printf %% doesn't use an arg:%%", 72));
	printf(" %d\n", printf("printf %% doesn't use an arg:%%", 72) + 3);

	printf(" %d\n", ft_printf("ft_printf %% doesn't work:%c%"));
	printf(" %d\n", printf("printf %% doesn't work:%c%"));

	printf(" %d\n", ft_printf("ft_printf % 1 ignores %:"));
	printf(" %d\n", printf("printf % 1 ignores %:") + 3);

	printf(" %d\n", ft_printf("ft_printf doesn't print char %:%%%%c", '%'));
	printf(" %d\n", printf("printf doesn't print char %:%%%%c", '%') + 3);

	printf(" %d\n", ft_printf("ft_printf mixing flags:%%%%c"));
	printf(" %d\n", printf("printf mixing flags:%%%%c") + 3);

	printf("============/Test s/============\n");

	printf(" %d\n", ft_printf("ft_printf just print string: %s", "string"));
	printf(" %d\n", printf("printf just print string: %s", "string") + 3);

	printf(" %d\n", ft_printf("ft_printf character ' ': %s", "' '"));
	printf(" %d\n", printf("printf character ' ': %s", "' '") + 3);

	printf(" %d\n", ft_printf("ft_printf null pointer: %s", p));
	printf(" %d\n", printf("printf null pointer: %s", p) + 3);

	printf(" %d\n", ft_printf("ft_printf no string: %s", "\0"));
	printf(" %d\n", printf("printf no string: %s", "\0") + 3);

	printf(" %d\n", ft_printf("ft_printf no string: %s", ""));
	printf(" %d\n", printf("printf no string: %s", "") + 3);

	printf("ft_printf not printable: %d\n", ft_printf("ft_printf   : [%s]\n", "\t"));
	printf("printf not printable: %d\n", printf("printf      : [%s]\n", "\t"));

	printf(" %d\n", ft_printf("ft_printf just print %s with %s", "string"));
	printf(" %d\n", printf("printf just print %s with %s", "string") + 3);

	printf(" %d\n", ft_printf("ft_printf just print spaces %s", "    "));
	printf(" %d\n", printf("printf just print spaces %s", "    ") + 3);

	printf(" %d\n", ft_printf("ft_printf just mixed %%%s%c", "string", '!'));
	printf(" %d\n", printf("printf just mixed %%%s%c", "string", '!') + 3);

	printf("============/Test d + i/============\n");

	printf(" %d\n", ft_printf("ft_printf just print decimal and int: %d %i", 25, -1));
	printf(" %d\n", printf("printf just print decimal and int: %d %i", 25, -1) + 3);

	printf(" %d\n", ft_printf("ft_printf all zeroes: %d %i", 0, 0));
	printf(" %d\n", printf("printf all zeroes: %d %i", 0, 0) + 3);

	printf(" %d\n", ft_printf("ft_printf just print min and max value: %d %i", -2147483648, 2147483647));
	printf(" %d\n", printf("printf just print min and max value: %d %i", -2147483648, 2147483647) + 3);

	printf(" %d\n", ft_printf("ft_printf overflow: %d %i", -2147483649, 2147483648));
	printf(" %d\n", printf("printf overflow: %d %i", -2147483649, 2147483648) + 3);

	printf(" %d\n", ft_printf("ft_printf just print characters: %d %i", 'a', 'b'));
	printf(" %d\n", printf("printf just print characters: %d %i", 'a', 'b') + 3);

	printf(" %d\n", ft_printf("ft_printf print without args: %d %i"));
	printf(" %d\n", printf("printf print without args: %d %i") + 3);

	printf(" %d\n", ft_printf("ft_printf just print hex: %d %i", 0xff, 0xff));
	printf(" %d\n", printf("printf just print hex: %d %i", 0xff, 0xff) + 3);

	printf(" %d\n", ft_printf("ft_printf just print zeroes hex: %d %i", 0x0, 0x0));
	printf(" %d\n", printf("printf just print zeroes hex: %d %i", 0x0, 0x0) + 3);

	printf(" %d\n", ft_printf("ft_printf just print hex overflow: %d %i", 0xFFFFFFFF, 0xFFFFFFFF));
	printf(" %d\n", printf("printf just print hex overflow: %d %i", 0xFFFFFFFF, 0xFFFFFFFF) + 3);

	printf(" %d\n", ft_printf("ft_printf print octal: %d %i", 010, 010));
	printf(" %d\n", printf("printf print octal: %d %i", 010, 010) + 3);

	printf(" %d\n", ft_printf("ft_printf print octal 0: %d %i", 00, 00));
	printf(" %d\n", printf("printf print octal 0: %d %i", 00, 00) + 3);

	printf(" %d\n", ft_printf("ft_printf print octal overflow: %d %i", 010000000000, 010000000000));
	printf(" %d\n", printf("printf print octal overflow: %d %i", 010000000000, 010000000000) + 3);

	printf(" %d\n", ft_printf("ft_printf print mix flags: %%%d%%%i", 0, 0));
	printf(" %d\n", printf("printf print mix flags: %%%d%%%i", 0, 0) + 3);
	
	printf("============/Test u/============\n");

	printf(" %d\n", ft_printf("ft_printf just print unsigned int: %u", 25));
	printf(" %d\n", printf("printf just print unsigned int: %u", 25) + 3);

	printf(" %d\n", ft_printf("ft_printf just print negative as unsigned int: %u", -1));
	printf(" %d\n", printf("printf just print negative as unsigned int: %u", -1) + 3);

	printf(" %d\n", ft_printf("ft_printf just print min and max value: %u %u", 0, 4294967295));
	printf(" %d\n", printf("printf just print min and max value: %u %u", 0, 4294967295) + 3);

	printf(" %d\n", ft_printf("ft_printf overflow: %u %u", -21, 4294967296));
	printf(" %d\n", printf("printf overflow: %u %u", -21, 4294967296) + 3);

	printf(" %d\n", ft_printf("ft_printf just print characters: %u %u", 'a', 'b'));
	printf(" %d\n", printf("printf just print characters: %u %u", 'a', 'b') + 3);

	printf(" %d\n", ft_printf("ft_printf print without args: %u %u"));
	printf(" %d\n", printf("printf print without args: %u %u") + 3);

	printf(" %d\n", ft_printf("ft_printf just print hex: %u", 0xff));
	printf(" %d\n", printf("printf just print hex: %u", 0xff) + 3);

	printf(" %d\n", ft_printf("ft_printf just print zeroes hex: %u", 0x0));
	printf(" %d\n", printf("printf just print zeroes hex: %u", 0x0) + 3);

	printf(" %d\n", ft_printf("ft_printf just print hex overflow: %u", 0x100000000));
	printf(" %d\n", printf("printf just print hex overflow: %u", 0x100000000) + 3);

	printf(" %d\n", ft_printf("ft_printf print octal: %u", 010));
	printf(" %d\n", printf("printf print octal: %u", 010) + 3);

	printf(" %d\n", ft_printf("ft_printf print octal 0: %u", 00));
	printf(" %d\n", printf("printf print octal 0: %u", 00) + 3);

	printf(" %d\n", ft_printf("ft_printf print octal overflow: %u", 010000000000));
	printf(" %d\n", printf("printf print octal overflow: %u", 010000000000) + 3);

	printf(" %d\n", ft_printf("ft_printf print mix flags: %%%u%%%u", 0, 0));
	printf(" %d\n", printf("printf print mix flags: %%%u%%%u", 0, 0) + 3);

	printf("============/Test x + X/============\n");

	printf(" %d\n", ft_printf("ft_printf just print in hex: %x %X", 258, 258));
	printf(" %d\n", printf("printf just print in hex: %x %X", 258, 258) + 3);

	printf(" %d\n", ft_printf("ft_printf just print negative as hex: %x %X", -1, -1));
	printf(" %d\n", printf("printf just print negative as hex: %x %X", -1, -1) + 3);

	printf(" %d\n", ft_printf("ft_printf just print min and max value: %x %X", 0, 4294967295));
	printf(" %d\n", printf("printf just print min and max value: %x %X", 0, 4294967295) + 3);

	printf(" %d\n", ft_printf("ft_printf overflow: %x %X", -21, 4294967296));
	printf(" %d\n", printf("printf overflow: %x %X", -21, 4294967296) + 3);

	printf(" %d\n", ft_printf("ft_printf just print characters: %x %X", 'a', 'b'));
	printf(" %d\n", printf("printf just print characters: %x %X", 'a', 'b') + 3);

	printf(" %d\n", ft_printf("ft_printf print without args: %x %X"));
	printf(" %d\n", printf("printf print without args: %x %X") + 3);

	printf(" %d\n", ft_printf("ft_printf just print hex: %x %X", 0xff, 0xff));
	printf(" %d\n", printf("printf just print hex: %x %X", 0xff, 0xff) + 3);

	printf(" %d\n", ft_printf("ft_printf just print zeroes hex: %x %X", 0x0, 0x0));
	printf(" %d\n", printf("printf just print zeroes hex: %x %X", 0x0, 0x0) + 3);

	printf(" %d\n", ft_printf("ft_printf just print hex overflow: %x %X", 0xFFFFFFFF, 0xFFFFFFFF));
	printf(" %d\n", printf("printf just print hex overflow: %x %X", 0xFFFFFFFF, 0xFFFFFFFF) + 3);

	printf(" %d\n", ft_printf("ft_printf print octal: %x %X", 010, 010));
	printf(" %d\n", printf("printf print octal: %x %X", 010, 010) + 3);

	printf(" %d\n", ft_printf("ft_printf print octal 0: %x %X", 00, 00));
	printf(" %d\n", printf("printf print octal 0: %x %X", 00, 00) + 3);

	printf(" %d\n", ft_printf("ft_printf print octal overflow: %x %X", 010000000000, 010000000000));
	printf(" %d\n", printf("printf print octal overflow: %x %X", 010000000000, 010000000000) + 3);

	printf(" %d\n", ft_printf("ft_printf print mix flags: %%%x%%%X", 0, 0));
	printf(" %d\n", printf("printf print mix flags: %%%x%%%X", 0, 0) + 3);

	printf("============/Test p/============\n");

	printf(" %d\n", ft_printf("ft_printf null pointer: %p", p));
	printf(" %d\n", printf("printf null pointer: %p", p) + 3);

	char s[] = "string";
	p = s;
	printf(" %d\n", ft_printf("ft_printf pointed memory: %p", p));
	printf(" %d\n", printf("printf pointed memory: %p", p) + 3);

	p = 0x0;
	printf(" %d\n", ft_printf("ft_printf hex null pointer: %p", p));
	printf(" %d\n", printf("printf hex null pointer: %p", p) + 3);

	printf(" %d\n", ft_printf("ft_printf print mix flags: %%%p%%%p", 0x0, 0x0));
	printf(" %d\n", printf("printf print mix flags: %%%p%%%p", 0x0, 0x0) + 3);
	return 0;
}