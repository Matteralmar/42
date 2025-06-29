/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:19:28 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:19:28 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*number_to_str(long number, size_t len)
{
	char	*str;
	long	n;

	n = number;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	str[len] = '\0';
	len--;
	while (len)
	{
		str[len] = (number % 10) + '0';
		number /= 10;
		len--;
	}
	if (n >= 0)
		str[0] = (number % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	number;

	number = n;
	len = len_calc(number);
	return (number_to_str(number, len));
}
