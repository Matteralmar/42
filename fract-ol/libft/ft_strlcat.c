/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:14:12 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:14:12 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_l;
	size_t	dst_l;

	src_l = ft_strlen(src);
	if (dstsize == 0)
		return (src_l);
	dst_l = ft_strlen(dst);
	if (dst_l >= dstsize)
		return (src_l + dstsize);
	i = 0;
	while (src[i] && (dst_l + i) < dstsize - 1)
	{
		dst[dst_l + i] = src[i];
		i++;
	}
	if (dst_l + i < dstsize)
		dst[dst_l + i] = '\0';
	return (src_l + dst_l);
}
