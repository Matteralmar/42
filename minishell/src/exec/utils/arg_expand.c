#include "minishell.h"

/*** @brief Handle exit status variable expansion*/
char	*expand_exit_status(char *str, t_info *info)
{
	char	*result;
	char	*temp;

	result = ft_itoa(info->last_exit_status);
	if (str[2])
	{
		temp = ft_strjoin(result, &str[2]);
		free(result);
		return (temp);
	}
	return (result);
}

/*** @brief Expand regular environment variable*/
char	*expand_env_var(char *str, size_t i, t_info *info)
{
	char	*var_name;
	char	*var_value;
	char	*result;
	char	*remainder;

	var_name = ft_substr(str, 1, i - 1);
	if (!var_name)
		return (ft_strdup(""));
	var_value = get_env_var(info->envs, var_name);
	free(var_name);
	if (!var_value)
		var_value = "";
	if (str[i])
	{
		remainder = ft_strdup(&str[i]);
		result = ft_strjoin(var_value, remainder);
		free(remainder);
	}
	else
		result = ft_strdup(var_value);
	if (!result)
		return (ft_strdup(""));
	return (result);
}

/*** @brief Expand environment variable or special parameter*/
char	*expand_variable(char *str, t_info *info)
{
	size_t	i;

	if (!str || str[0] != '$')
		return (ft_strdup(str));
	if (str[1] == '?')
		return (expand_exit_status(str, info));
	if (str[1] == '*' || str[1] == '@' || str[1] == '#'
		|| ft_isdigit(str[1]))
	{
		if (str[2])
			return (ft_strdup(&str[2]));
		return (ft_strdup(""));
	}
	i = 1;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	if (i == 1)
		return (ft_strdup(str));
	return (expand_env_var(str, i, info));
}

/*** @brief Get environment variable value from name*/
static char	*get_env_var_value(char *text, size_t *i, t_info *info)
{
	char	*temp;
	char	*var_val;
	size_t	start;
	size_t	len;

	start = *i;
	while (text[*i] && (ft_isalnum(text[*i]) || text[*i] == '_'))
		(*i)++;
	len = *i - start;
	temp = ft_substr(text, start, len);
	var_val = get_env_var(info->envs, temp);
	free(temp);
	if (var_val)
		return (ft_strdup(var_val));
	return (ft_strdup(""));
}

/*** @brief Get variable value for expansion in text*/
char	*get_var_value(char *text, size_t *i, t_info *info)
{
	if (text[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(info->last_exit_status));
	}
	if (text[*i] == '*' || text[*i] == '@' || text[*i] == '#'
		|| ft_isdigit(text[*i]))
	{
		(*i)++;
		return (ft_strdup(""));
	}
	if (ft_isalpha(text[*i]) || text[*i] == '_')
		return (get_env_var_value(text, i, info));
	return (ft_strdup("$"));
}
