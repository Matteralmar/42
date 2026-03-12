/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:31:01 by ahavrank          #+#    #+#             */
/*   Updated: 2024/06/25 17:27:09 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/* int	main(void)
{
	char str1[50] = "Naomi objednala poke bowl.";
	char str2[50] = "juchuuuuu";
	size_t size = 30;
	ft_memcpy(str1, str2, size);
	char *dst = "hbkcdkvfjjskjv";
	char *src = "kja";
	size_t srcsize = 50;
	size_t dstlen;

	dstlen = ft_strlen(dst);
	ft_memcpy(dst, src, srcsize);
	return (0);
} */
