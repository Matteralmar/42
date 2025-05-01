/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:48:38 by aartimez          #+#    #+#             */
/*   Updated: 2025/04/29 17:41:42 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*r;
	int	i;

	if (min >= max)
		return (NULL);
	r = (int *)malloc((max - min) * sizeof(int));
	if (!r)
	{
		return (NULL);
	}
	i = min;
	while (i < max)
	{
		r[i - min] = i;
		i++;
	}
	return (r);
}
