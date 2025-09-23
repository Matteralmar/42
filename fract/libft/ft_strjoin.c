/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:15:02 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:15:02 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
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
