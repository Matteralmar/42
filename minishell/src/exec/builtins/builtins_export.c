#include "minishell.h"

/*** @brief Process a single export argument*/
static int	process_export_arg(char *arg, t_info *info)
{
	char	*var_name;
	char	*var_value;
	int		status;

	if (!is_valid_identifier(arg))
		return (ft_dprintf("export: `%s': not a valid identifier\n", arg), 1);
	var_name = extract_var_name(arg);
	if (!var_name)
		return (1);
	var_value = extract_var_value(arg);
	status = set_env_var(info->envs, var_name, var_value);
	free(var_name);
	if (var_value)
		free(var_value);
	return (status);
}

/*** @brief Export environment variables*/
int	builtin_export(char **args, t_info *info)
{
	int	i;
	int	status;

	if (!args[1])
		return (print_export_vars(info->envs->vars));
	status = 0;
	i = 1;
	while (args[i])
	{
		if (process_export_arg(args[i], info) != 0)
			status = 1;
		i++;
	}
	return (status);
}

/*** @brief Unset environment variables*/
int	builtin_unset(char **args, t_info *info)
{
	int	i;
	int	status;

	if (!args[1])
		return (0);
	status = 0;
	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '=') || !is_valid_identifier(args[i]))
		{
			ft_dprintf("unset: `%s': not a valid identifier\n", args[i]);
			status = 1;
		}
		else if (unset_env_var(info->envs, args[i]) != 0)
			status = 1;
		i++;
	}
	return (status);
}
