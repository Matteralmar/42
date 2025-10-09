/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:12:51 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:12:51 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	st;
	size_t	s_l;
	char	*sub;

	st = (size_t) start;
	if (!s)
		return (NULL);
	s_l = ft_strlen(s);
	if (st >= s_l)
		return (ft_strdup(""));
	if (st + len > s_l)
		len = s_l - st;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, &s[st], len);
	sub[len] = '\0';
	return (sub);
}
