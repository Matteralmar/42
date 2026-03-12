#include "minishell.h"

/*** @brief Check if string is a valid number*/
static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*** @brief Handle exit arguments and set exit code*/
static int	handle_exit_args(char **args, int *exit_code)
{
	long	num;

	if (!is_valid_number(args[1]))
	{
		ft_dprintf("minishell: exit: %s: numeric argument required\n",
			args[1]);
		*exit_code = 2;
		return (0);
	}
	else if (args[2])
	{
		ft_dprintf("minishell: exit: too many arguments\n");
		return (1);
	}
	num = ft_atoi(args[1]);
	*exit_code = (unsigned char)num;
	return (0);
}

/*** @brief Exit minishell*/
int	builtin_exit(char **args, t_info *info)
{
	int		exit_code;

	exit_code = 0;
	if (args[1])
	{
		if (handle_exit_args(args, &exit_code))
			return (1);
	}
	if (info->interactive)
		ft_printf("exit\n");
	exit(exit_code);
}
