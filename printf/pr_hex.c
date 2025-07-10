/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:59:29 by gvasylie          #+#    #+#             */
/*   Updated: 2025/06/07 14:59:29 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	len_calc(uintptr_t number)
{
	size_t	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number >= 16)
	{
		number /= 16;
		len++;
	}
	len++;
	return (len);
}

static	void	print_hex_recursive(uintptr_t nbr, char *base)
{
	if (nbr >= 16)
		print_hex_recursive(nbr / 16, base);
	write(1, &base[nbr % 16], 1);
}

size_t	pr_hex(uintptr_t nbr, char *base)
{
	size_t	len;

	len = len_calc(nbr);
	print_hex_recursive(nbr, base);
	return (len);
}

size_t	pr_ptr(void *ptr)
{
	uintptr_t	addr;
	size_t		len;

	if (!ptr)
		return (pr_str("(nil)"));
	len = 0;
	addr = (uintptr_t)ptr;
	write(1, "0x", 2);
	len += 2;
	len += pr_hex(addr, "0123456789abcdef");
	return (len);
}
