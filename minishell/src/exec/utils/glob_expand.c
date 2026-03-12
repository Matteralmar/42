#include "minishell.h"

/*** @brief Process matches and build result*/
static char	*process_matches(char **matches, int count)
{
	char	*result;

	bubble_sort(matches, count);
	result = build_result(matches, count);
	free_matches(matches, count);
	return (result);
}

/*** @brief Main wildcard expansion function*/
char	*expand_wildcard(const char *pattern)
{
	char	**matches;
	int		count;

	if (!pattern || !ft_strchr(pattern, '*'))
		return (ft_strdup(pattern));
	matches = scan_directory(pattern, &count);
	if (!matches || count == 0)
	{
		if (matches)
			free(matches);
		return (ft_strdup(pattern));
	}
	return (process_matches(matches, count));
}
