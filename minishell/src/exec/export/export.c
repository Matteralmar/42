#include "minishell.h"

/*** @brief Check if string is valid identifier for environment variable*/
int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (!ft_isalpha(*str) && *str != '_')
		return (0);
	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

/*** @brief Extract variable name from export argument*/
char	*extract_var_name(char *str)
{
	char	*var_name;
	char	*equals;
	int		len;

	equals = ft_strchr(str, '=');
	if (!equals)
		return (ft_strdup(str));
	len = equals - str;
	var_name = malloc(sizeof(char) * (len + 1));
	if (!var_name)
		return (NULL);
	ft_strlcpy(var_name, str, len + 1);
	return (var_name);
}

/*** @brief Extract variable value from export argument*/
char	*extract_var_value(char *str)
{
	char	*equals;

	equals = ft_strchr(str, '=');
	if (!equals)
		return (NULL);
	return (ft_strdup(equals + 1));
}

/*** @brief Print all exported variables in sorted order*/
int	print_export_vars(char **env)
{
	char	**sorted_env;
	int		count;

	count = count_env_vars(env);
	if (count == 0)
		return (0);
	sorted_env = alloc_sorted_env(env, count);
	if (!sorted_env)
		return (1);
	sort_env_array(sorted_env, count);
	print_sorted_env(sorted_env);
	free_env_arr(sorted_env);
	return (0);
}
