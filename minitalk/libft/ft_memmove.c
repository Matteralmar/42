/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:18:31 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:18:31 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_c;
	unsigned char	*dst_c;
	size_t			i;

	if (dst == src || len == 0)
		return (dst);
	src_c = (unsigned char *)src;
	dst_c = (unsigned char *)dst;
	i = 0;
	if (dst_c > src_c)
	{
		while (len-- > 0)
			dst_c[len] = src_c[len];
	}
	else
	{
		while (i < len)
		{
			dst_c[i] = src_c[i];
			i++;
		}
	}
	return (dst);
}
