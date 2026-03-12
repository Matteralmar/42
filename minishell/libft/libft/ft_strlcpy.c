/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivantso <vivantso@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:11:38 by vivantso          #+#    #+#             */
/*   Updated: 2025/05/23 13:11:38 by vivantso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	n;

	n = 0;
	if (size > 0)
	{
		while (n < (size - 1) && src[n])
		{
			dest[n] = src[n];
			n++;
		}
		dest[n] = '\0';
	}
	while (src[n])
		n++;
	return (n);
}
