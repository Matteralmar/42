#include "minishell.h"

/*** @brief Search for command in PATH directories*/
char	*search_in_path(char *cmd, char **paths)
{
	char	*dir;
	char	*full_path;
	int		i;

	i = -1;
	full_path = NULL;
	while (paths[++i])
	{
		dir = ft_strjoin(paths[i], "/");
		if (!dir)
			break ;
		full_path = ft_strjoin(dir, cmd);
		free(dir);
		if (!full_path)
			break ;
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		full_path = NULL;
	}
	return (NULL);
}

/*** @brief Free array of path strings*/
void	free_paths(char **paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}
