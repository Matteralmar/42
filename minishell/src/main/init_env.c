#include "minishell.h"

/*** @brief If allocation of env vars fails free all other vars*/
static int	loop_iffree(t_env *envs, char **env, size_t *i)
{
	envs->vars[*i] = ft_strdup(env[*i]);
	if (!envs->vars[*i])
	{
		while (*i > 0)
			free(envs->vars[--(*i)]);
		free(envs->vars);
		free(envs);
		return (1);
	}
	(*i)++;
	return (0);
}

/*** @brief Creates env list with env element where all env values are stored
 * and writes capacity element for future usage*/
static t_env	*ft_envlst(char **env)
{
	t_env	*envs;
	size_t	i;

	envs = malloc(sizeof(t_env));
	if (!envs)
		return (NULL);
	envs->vars = malloc(sizeof(char *) * ENV_CAPACITY);
	if (!envs->vars)
		return (free(envs), NULL);
	envs->vars[ENV_CAPACITY - 1] = NULL;
	envs->cap = ENV_CAPACITY;
	i = 0;
	while (env[i] && i < ENV_CAPACITY - 1)
	{
		if (loop_iffree(envs, env, &i))
			return (NULL);
	}
	envs->vars[i] = NULL;
	return (envs);
}

/*** @brief Initialization of env struct*/
int	init_env(char **env, t_info *info)
{
	info->envs = ft_envlst(env);
	if (!info->envs)
		return (ft_dprintf("Malloc allocation failed"), 1);
	return (0);
}
