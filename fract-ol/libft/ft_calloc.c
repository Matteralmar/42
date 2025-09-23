/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:19:50 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:19:50 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*n;

	if (count == 0 || size == 0)
		return (malloc(0));
	if ((size_t)-1 / size < count)
		return (NULL);
	n = malloc(count * size);
	if (!n)
		return (NULL);
	ft_bzero(n, count * size);
	return (n);
}
