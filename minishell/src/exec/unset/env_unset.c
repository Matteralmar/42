#include <stdlib.h>
#include "minishell.h"

/*** @brief Copy environment array excluding specified index*/
static int	copy_env_except_index(char **new_env, char **old_env, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (old_env[i])
	{
		if (i != index)
		{
			new_env[j] = ft_strdup(old_env[i]);
			if (!new_env[j])
			{
				while (--j >= 0)
					free(new_env[j]);
				free(new_env);
				return (1);
			}
			j++;
		}
		i++;
	}
	new_env[j] = NULL;
	return (0);
}

/*** @brief Unset (remove) environment variable*/
int	unset_env_var(t_env *env, char *var)
{
	char	**new_env;
	int		index;
	int		env_count;

	if (!env || !env->vars || !var)
		return (1);
	index = find_env_index(env, var);
	if (index < 0)
		return (0);
	env_count = count_env_vars(env->vars);
	if (env_count <= 1)
	{
		free_env_arr(env->vars);
		env->vars = malloc(sizeof(char *));
		if (!env->vars)
			return (1);
		env->vars[0] = NULL;
		return (0);
	}
	new_env = malloc(sizeof(char *) * env_count);
	if (!new_env || copy_env_except_index(new_env, env->vars, index))
		return (1);
	free_env_arr(env->vars);
	env->vars = new_env;
	return (0);
}
