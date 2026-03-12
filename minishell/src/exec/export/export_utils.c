#include "minishell.h"

/*** @brief Allocate and copy environment array for sorting*/
char	**alloc_sorted_env(char **env, int count)
{
	char	**sorted_env;
	int		i;

	sorted_env = malloc(sizeof(char *) * (count + 1));
	if (!sorted_env)
		return (NULL);
	i = 0;
	while (i < count)
	{
		sorted_env[i] = ft_strdup(env[i]);
		if (!sorted_env[i])
		{
			while (--i >= 0)
				free(sorted_env[i]);
			free(sorted_env);
			return (NULL);
		}
		i++;
	}
	sorted_env[i] = NULL;
	return (sorted_env);
}

/*** @brief Sort environment array alphabetically*/
void	sort_env_array(char **sorted_env, int count)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strncmp(sorted_env[i], sorted_env[j],
					ft_strlen(sorted_env[i])) > 0)
			{
				tmp = sorted_env[i];
				sorted_env[i] = sorted_env[j];
				sorted_env[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

/*** @brief Print sorted environment in export format*/
void	print_sorted_env(char **sorted_env)
{
	char	*equals;
	int		i;

	i = 0;
	while (sorted_env[i])
	{
		equals = ft_strchr(sorted_env[i], '=');
		if (equals)
		{
			write(1, "declare -x ", 11);
			write(1, sorted_env[i], equals - sorted_env[i]);
			write(1, "=\"", 2);
			write(1, equals + 1, ft_strlen(equals + 1));
			write(1, "\"\n", 2);
		}
		else
			ft_printf("declare -x %s\n", sorted_env[i]);
		i++;
	}
}
