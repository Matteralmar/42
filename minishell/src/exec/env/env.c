#include <stdlib.h>
#include "minishell.h"

/*** @brief Get environment variable value by name*/
char	*get_env_var(t_env *env, char *var)
{
	int	i;
	int	len;

	if (!env || !env->vars || !var)
		return (NULL);
	len = ft_strlen(var);
	i = 0;
	while (env->vars[i])
	{
		if (ft_strncmp(env->vars[i], var, len) == 0
			&& env->vars[i][len] == '=')
			return (env->vars[i] + len + 1);
		i++;
	}
	return (NULL);
}

/*** @brief Create environment string in format VAR=value*/
static char	*create_env_string(char *var, char *value)
{
	char	*temp;
	char	*new_var;

	temp = ft_strjoin(var, "=");
	if (!temp)
		return (NULL);
	if (value)
	{
		new_var = ft_strjoin(temp, value);
		free(temp);
		return (new_var);
	}
	return (temp);
}

/*** @brief Add new environment variable to array*/
static int	add_new_env_var(t_env *env, char *new_var)
{
	char	**new_env;
	int		env_count;

	env_count = count_env_vars(env->vars);
	new_env = create_new_env(env->vars, env_count + 1);
	if (!new_env)
		return (1);
	new_env[env_count] = new_var;
	new_env[env_count + 1] = NULL;
	free_env_arr(env->vars);
	env->vars = new_env;
	return (0);
}

/*** @brief Set or update environment variable*/
int	set_env_var(t_env *env, char *var, char *value)
{
	char	*new_var;
	int		index;

	if (!env || !var)
		return (1);
	new_var = create_env_string(var, value);
	if (!new_var)
		return (1);
	index = find_env_index(env, var);
	if (index >= 0)
	{
		free(env->vars[index]);
		env->vars[index] = new_var;
		return (0);
	}
	if (add_new_env_var(env, new_var))
		return (free(new_var), 1);
	return (0);
}

int	update_last_status(t_info *info, int status)
{
	char	*status_str;

	status_str = ft_itoa(status);
	if (!status_str)
		return (1);
	set_env_var(info->envs, "?", status_str);
	free(status_str);
	info->last_exit_status = status;
	return (1);
}
