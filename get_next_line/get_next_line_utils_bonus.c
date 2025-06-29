/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 10:13:11 by gvasylie          #+#    #+#             */
/*   Updated: 2025/06/29 13:12:51 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(char *d, char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < ((n / 8) * 8))
	{
		*((size_t *)(d + i)) = *((const size_t *)(s + i));
		i += 8;
	}
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strchr(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_substr(char *s, size_t st, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, &s[st], len);
	sub[len] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*ns;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ns = (char *)malloc(len1 + len2 + 1);
	if (!ns)
		return (NULL);
	ft_memcpy(ns, s1, len1);
	ft_memcpy(ns + len1, s2, len2);
	ns[len1 + len2] = '\0';
	return (ns);
}
