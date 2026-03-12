#include "minishell.h"

/*** @brief Print all environment variables*/
int	builtin_env(t_info *info)
{
	int	i;

	if (!info || !info->envs || !info->envs->vars)
		return (1);
	i = 0;
	while (info->envs->vars[i])
	{
		ft_printf("%s\n", info->envs->vars[i]);
		i++;
	}
	return (0);
}

/*** @brief Print arguments for echo command*/
static int	echo_print_args(char **args, int start)
{
	int	i;

	i = start;
	while (args[i])
	{
		ft_printf("%s", args[i]);
		if (args[i + 1])
			ft_printf(" ");
		i++;
	}
	return (0);
}

/*** @brief Echo command implementation*/
int	builtin_echo(char **args)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (args[1] && ft_strncmp(args[1], "-n", 3) == 0)
	{
		newline = 0;
		i = 2;
	}
	echo_print_args(args, i);
	if (newline)
		ft_printf("\n");
	return (0);
}
