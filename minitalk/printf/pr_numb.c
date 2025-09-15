/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_numb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:59:18 by gvasylie          #+#    #+#             */
/*   Updated: 2025/06/07 14:59:18 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	len_calc(long number)
{
	size_t	len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number = -number;
		len++;
	}
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	len++;
	return (len);
}

static void	print_numb_recursive(long n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		print_numb_recursive(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

size_t	pr_numb(int n)
{
	size_t	len;

	len = len_calc((long)n);
	print_numb_recursive((long)n);
	return (len);
}
