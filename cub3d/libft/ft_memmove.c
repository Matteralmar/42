/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:34:29 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/25 17:25:52 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*dstlen;
	const char	*srclen;

	i = 0;
	if (!dest && !src)
		return (NULL);
	dstlen = dest;
	srclen = src;
	if (dstlen > srclen)
	{
		while (len-- > i)
		{
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		while (len > i)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/* int	main(void)
{
	char str1[50] = "Naomi objednala poke bowl.";
	char str2[50] = "juchuuuuu";
	size_t size = 15;
	ft_memmove(str1, str2, size);
	return (0);
}
 */
