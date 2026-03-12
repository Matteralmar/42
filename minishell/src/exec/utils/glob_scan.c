#include "minishell.h"

/*** @brief Get matches for wildcard pattern by scanning directory*/
char	**scan_directory(const char *pattern, int *count)
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
