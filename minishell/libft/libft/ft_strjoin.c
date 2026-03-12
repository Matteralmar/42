/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivantso <vivantso@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:49:37 by vivantso          #+#    #+#             */
/*   Updated: 2025/05/27 18:12:08 by vivantso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newarr;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newarr = (char *)malloc((len1 + len2) * sizeof(char) + 1);
	if (!newarr)
		return (NULL);
	ft_strlcpy(newarr, s1, len1 + len2 + 1);
	ft_strlcat(newarr, s2, len1 + len2 + 1);
	return (newarr);
}
