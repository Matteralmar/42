/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaligula <kaligula@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:17:18 by vivantso          #+#    #+#             */
/*   Updated: 2025/10/25 10:33:30 by kaligula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destin;
	const unsigned char	*source;

	if (!dest || !src)
		return (NULL);
	if (!dest && !src && n > 0)
		return (NULL);
	if (!dest && !src && n == 0)
		return (dest);
	destin = (unsigned char *)dest;
	source = (const unsigned char *)src;
	while (n--)
		*destin++ = *source++;
	return (dest);
}
