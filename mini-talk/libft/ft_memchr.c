/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:18:45 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:18:45 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		c_c;
	const unsigned char	*tmp;

	c_c = (unsigned char)c;
	tmp = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == c_c)
			return ((void *)&tmp[i]);
		i++;
	}
	return (NULL);
}
