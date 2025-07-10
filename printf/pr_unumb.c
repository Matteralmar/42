/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_unumb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:59:08 by gvasylie          #+#    #+#             */
/*   Updated: 2025/06/07 14:59:08 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	size_t	len_calc(unsigned int number)
{
	size_t	len;

	len = 0;
	if (number == 0)
		return (1);
	while (number >= 10)
	{
		number /= 10;
		len++;
	}
	len++;
	return (len);
}

static void	print_numb_recursive(unsigned int n)
{
	if (n >= 10)
		print_numb_recursive(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

size_t	pr_unumb(unsigned int n)
{
	size_t	len;

	len = len_calc(n);
	print_numb_recursive(n);
	return (len);
}
