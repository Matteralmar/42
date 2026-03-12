#include "minishell.h"

/*** @brief Get builtin map*/
static t_builtin_map	*get_builtins(void)
{
	static t_builtin_map	builtins[] = {
	{"echo", builtin_echo, NULL, 0},
	{"cd", NULL, builtin_cd, 1},
	{"pwd", builtin_pwd, NULL, 0},
	{"export", NULL, builtin_export, 1},
	{"unset", NULL, builtin_unset, 1},
	{"env", NULL, NULL, 2},
	{"exit", NULL, builtin_exit, 1},
	{NULL, NULL, NULL, 0}
	};

	return (builtins);
}

/*** @brief Check if command is a builtin*/
int	is_builtin(char *cmd)
{
	t_builtin_map	*builtins;
	int				i;

	if (!cmd)
		return (0);
	builtins = get_builtins();
	i = 0;
	while (builtins[i].name)
	{
		if (ft_strncmp(cmd, builtins[i].name,
				ft_strlen(builtins[i].name) + 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

/*** @brief Execute builtin command*/
int	exec_builtin(char **args, t_info *info)
{
	t_builtin_map	*builtins;
	int				i;

	if (!args || !args[0])
		return (1);
	builtins = get_builtins();
	i = 0;
	while (builtins[i].name)
	{
		if (ft_strncmp(args[0], builtins[i].name,
				ft_strlen(builtins[i].name) + 1) == 0)
		{
			if (builtins[i].needs_info == 2)
				return (builtin_env(info));
			if (builtins[i].needs_info)
				return (builtins[i].func_with_info(args, info));
			return (builtins[i].func_no_info(args));
		}
		i++;
	}
	return (1);
}
