/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:12:59 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:12:59 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	to_trim(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	st;
	size_t	len;

	if (!set)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(""));
	st = 0;
	len = ft_strlen(s1);
	while (st < len && to_trim(s1[st], set))
		st++;
	if (st == len)
		return (ft_strdup(""));
	while (len > st && to_trim(s1[len - 1], set))
		len--;
	return (ft_substr(s1, st, len - st));
}
