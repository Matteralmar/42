/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:13:07 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:13:07 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	c_c;
	char	*tmp;

	c_c = (char)c;
	tmp = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c_c)
			tmp = (char *)&s[i];
		i++;
	}
	if (s[i] == c_c)
		tmp = (char *)&s[i];
	return (tmp);
}
