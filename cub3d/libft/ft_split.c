/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anezkahavrankova <anezkahavrankova@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:51:36 by anezkahavra       #+#    #+#             */
/*   Updated: 2024/06/23 23:31:37 by anezkahavra      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numstrings(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i != 0 && s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	if (s[ft_strlen(s) - 1] == c)
		j = j - 1;
	if (s[0] == '\0')
		j = j - 1;
	return (j + 1);
}

unsigned int	findend(const char *s, int c, int i)
{
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			break ;
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int					str_i;
	unsigned int		i;
	char				**result;

	result = malloc(((ft_numstrings(s, c)) + 1) * (sizeof(char *)));
	if (result == NULL)
		return (NULL);
	i = 0;
	str_i = 0;
	while (i < (ft_strlen)(s))
	{
		while (s[i] == c)
			i++;
		if (i < findend(s, c, i))
		{
			result[str_i] = malloc(sizeof(char) * ((findend(s, c, i) - i) + 1));
			if (result[str_i] == NULL)
				return (NULL);
			ft_strlcpy(result[str_i], &(s[i]), (findend(s, c, i) - i + 1));
			str_i++;
			i = findend(s, c, i);
		}
	}
	result[str_i] = NULL;
	return (result);
}

/* int main(void)
{
	char const str[60] = "ANEZKAISVERYCUTE3<3";
	char c = ' ';
	int i = 0;
	char **res = ft_split(str, c);
	while (res[i] != NULL) {
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
} */