/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:13:23 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:13:23 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*n_s;
	size_t	s_l;

	if (!s)
		return (NULL);
	s_l = ft_strlen(s);
	i = 0;
	n_s = (char *)malloc(s_l + 1);
	if (!n_s)
		return (NULL);
	while (s[i])
	{
		n_s[i] = f(i, s[i]);
		i++;
	}
	n_s[i] = '\0';
	return (n_s);
}
