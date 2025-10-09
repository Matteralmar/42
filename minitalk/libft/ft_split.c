/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 13:17:57 by gvasylie          #+#    #+#             */
/*   Updated: 2025/05/29 13:17:57 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			words++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			words++;
		i++;
	}
	return (words);
}

static void	copy_strs(const char *s, char c, char **strs)
{
	size_t	i;
	size_t	j;
	size_t	start;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			len = i - start;
			ft_memcpy(strs[j], s + start, len);
			strs[j][len] = '\0';
			j++;
		}
	}
}

static void	free_strs(char **strs, size_t j)
{
	while (j > 0)
	{
		j--;
		free(strs[j]);
	}
	free(strs);
}

static char	**strs_malloc_allocate(const char *s, char c, size_t i, char **strs)
{
	size_t	j;
	size_t	start;

	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i++;
			strs[j] = (char *)malloc((i - start) + 1);
			if (!strs[j])
			{
				free_strs(strs, j);
				return (NULL);
			}
			j++;
		}
	}
	return (strs);
}

char	**ft_split(const char *s, char c)
{
	size_t	words;
	char	**strs;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	strs = malloc(sizeof(*strs) * (words + 1));
	if (!strs)
		return (NULL);
	if (strs_malloc_allocate(s, c, 0, strs))
	{
		copy_strs(s, c, strs);
		strs[words] = NULL;
	}
	else
		return (NULL);
	return (strs);
}
