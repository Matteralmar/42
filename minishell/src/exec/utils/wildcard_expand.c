#include "minishell.h"

/*** @brief Initialize matches array*/
static char	**init_matches_array(int *capacity)
{
	char	**matches;

	*capacity = 32;
	matches = malloc(sizeof(char *) * (*capacity));
	return (matches);
}

/*** @brief Get matches for wildcard pattern*/
static char	**scan_directory(const char *pattern, int *count)
{
	DIR				*dir;
	struct dirent	*entry;
	char			**matches;
	int				capacity;

	*count = 0;
	matches = init_matches_array(&capacity);
	if (!matches)
		return (NULL);
	dir = opendir(".");
	if (!dir)
		return (free(matches), NULL);
	while (1)
	{
		entry = readdir(dir);
		if (!entry)
			break ;
		if (entry->d_name[0] == '.' && pattern[0] != '.')
			continue ;
		if (match_pattern(entry->d_name, pattern))
			if (add_match(&matches, count, &capacity, entry->d_name) < 0)
				return (closedir(dir), NULL);
	}
	closedir(dir);
	return (matches);
}

/*** @brief Free matches array*/
static void	free_matches(char **matches, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(matches[i++]);
	free(matches);
}

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
