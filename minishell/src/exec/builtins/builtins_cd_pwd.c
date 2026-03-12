#include "minishell.h"

/*** @brief Get target path for cd command*/
static char	*get_cd_path(char **args, t_info *info)
{
	char	*path;
	char	*home;

	if (!args[1] || ft_strncmp(args[1], "~", 2) == 0)
	{
		home = get_env_var(info->envs, "HOME");
		if (!home)
			return (ft_dprintf("minishell: cd: HOME not set\n"), NULL);
		return (home);
	}
	else if (ft_strncmp(args[1], "-", 2) == 0)
	{
		path = get_env_var(info->envs, "OLDPWD");
		if (!path)
			return (ft_dprintf("minishell: cd: OLDPWD not set\n"), NULL);
		ft_printf("%s\n", path);
		return (path);
	}
	return (args[1]);
}

/*** @brief Update PWD and OLDPWD environment variables*/
static int	update_pwd_vars(t_info *info, char *curr_pwd)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		if (curr_pwd)
		{
			set_env_var(info->envs, "OLDPWD", curr_pwd);
			free(curr_pwd);
		}
		set_env_var(info->envs, "PWD", cwd);
		free(cwd);
	}
	return (0);
}

/*** @brief Change current directory*/
int	builtin_cd(char **args, t_info *info)
{
	char	*path;
	char	*curr_pwd;

	if (args[1] && args[2])
	{
		ft_dprintf("cd: too many arguments\n");
		return (1);
	}
	path = get_cd_path(args, info);
	if (!path)
		return (1);
	curr_pwd = get_env_var(info->envs, "PWD");
	if (!curr_pwd)
		curr_pwd = getcwd(NULL, 0);
	else
		curr_pwd = ft_strdup(curr_pwd);
	if (chdir(path) != 0)
	{
		ft_dprintf("minishell: cd: %s: %s\n", path, strerror(errno));
		if (curr_pwd)
			free(curr_pwd);
		return (1);
	}
	return (update_pwd_vars(info, curr_pwd));
}

/*** @brief Print working directory*/
int	builtin_pwd(char **args)
{
	char	*cwd;

	(void)args;
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		ft_dprintf("minishell: pwd: %s\n", strerror(errno));
		return (1);
	}
	ft_printf("%s\n", cwd);
	free(cwd);
	return (0);
}
