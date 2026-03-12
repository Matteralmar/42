#include <stdlib.h>
#include "minishell.h"

/*** @brief Count number of environment variables*/
int	count_env_vars(char **env)
{
	int	count;

	count = 0;
	if (!env)
		return (count);
	while (env[count])
		count++;
	return (count);
}

/*** @brief Free environment array*/
void	free_env_arr(char **env)
{
	int	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

/*** @brief Find index of environment variable by name*/
int	find_env_index(t_env *env, char *var)
{
	int	i;
	int	len;

	if (!env || !env->vars || !var)
		return (-1);
	len = ft_strlen(var);
	i = 0;
	while (env->vars[i])
	{
		if (ft_strncmp(env->vars[i], var, len) == 0
			&& env->vars[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

/*** @brief Create new environment array with specified size*/
char	**create_new_env(char **old_env, int new_size)
{
	char	**new_env;
	int		i;

	new_env = malloc(sizeof(char *) * (new_size + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	if (old_env)
	{
		while (old_env[i] && i < new_size)
		{
			new_env[i] = ft_strdup(old_env[i]);
			if (!new_env[i])
				return (free_env_arr(new_env), NULL);
			i++;
		}
	}
	new_env[i] = NULL;
	return (new_env);
}
