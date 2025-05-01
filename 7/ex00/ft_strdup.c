/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:35:50 by aartimez          #+#    #+#             */
/*   Updated: 2025/04/29 15:20:04 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i] != '\0')
		i++;
	copy = malloc((i + 1) * sizeof (char));
	if (copy)
	{
		i = 0;
		while (src[i] != '\0')
		{
			copy[i] = src[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	else
		return (NULL);
}
