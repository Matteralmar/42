#include "minishell.h"
#include <dirent.h>

/*** @brief Check if pattern matches string (simple glob matching)*/
int	match_pattern(const char *str, const char *pattern)
{
	if (!*pattern)
		return (!*str);
	if (*pattern == '*')
	{
		if (match_pattern(str, pattern + 1))
			return (1);
		if (*str && match_pattern(str + 1, pattern))
			return (1);
		return (0);
	}
	if (*str == *pattern)
		return (match_pattern(str + 1, pattern + 1));
	return (0);
}

/*** @brief Bubble sort for string array*/
void	bubble_sort(char **matches, int count)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < count - 1)
	{
		j = 0;
		while (j < count - i - 1)
		{
			if (ft_strncmp(matches[j], matches[j + 1],
					ft_strlen(matches[j]) + 1) > 0)
			{
				tmp = matches[j];
				matches[j] = matches[j + 1];
				matches[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*** @brief Build result string from matches*/
char	*build_result(char **matches, int count)
{
	char	*result;
	char	*temp;
	int		i;

	if (count == 0)
		return (NULL);
	result = ft_strdup(matches[0]);
	if (!result)
		return (NULL);
	i = 1;
	while (i < count)
	{
		temp = ft_strjoin(result, " ");
		free(result);
		if (!temp)
			return (NULL);
		result = temp;
		temp = ft_strjoin(result, matches[i]);
		free(result);
		if (!temp)
			return (NULL);
		result = temp;
		i++;
	}
	return (result);
}

/*** @brief Add match to matches array*/
int	add_match(char ***matches, int *count, int *cap, char *name)
{
	char	**new_matches;
	int		i;

	if (*count >= *cap - 1)
	{
		*cap *= 2;
		new_matches = malloc(sizeof(char *) * (*cap));
		if (!new_matches)
			return (-1);
		i = 0;
		while (i < *count)
		{
			new_matches[i] = (*matches)[i];
			i++;
		}
		free(*matches);
		*matches = new_matches;
	}
	(*matches)[*count] = ft_strdup(name);
	if (!(*matches)[*count])
		return (-1);
	(*count)++;
	return (0);
}
