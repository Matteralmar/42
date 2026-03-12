#include "minishell.h"

/*** @brief Find command path in PATH environment variable*/
char	*find_cmd_path(char *cmd, t_info *info)
{
	char	*path;
	char	**paths;
	char	*result;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	path = get_env_var(info->envs, "PATH");
	if (!path)
		return (NULL);
	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	result = search_in_path(cmd, paths);
	free_paths(paths);
	return (result);
}

/*** @brief Handle builtin command execution*/
static int	exec_builtin_cmd(t_ast *ast, t_info *info)
{
	char	**args_arr;
	int		status;

	if (ast->redirs || ast->start_redirs)
		return (exec_builtin_with_redir(ast, info));
	args_arr = args_to_array(ast->args, info);
	if (!args_arr)
		return (1);
	status = exec_builtin(args_arr, info);
	free_paths(args_arr);
	return (status);
}

/*** @brief Handle external command execution*/
static int	exec_ext_cmd(t_ast *ast, t_info *info, char *cmd_path)
{
	char	**args_arr;
	int		status;

	args_arr = args_to_array(ast->args, info);
	if (!args_arr)
		return (free(cmd_path), 1);
	status = exec_external_cmd(ast, info, cmd_path, args_arr);
	free(cmd_path);
	free_paths(args_arr);
	return (status);
}

/*** @brief Execute command with args (builtin or external)*/
static int	exec_with_args(t_ast *ast, t_info *info, char **args_arr)
{
	char	*cmd_path;

	if (is_builtin(args_arr[0]))
		return (free_paths(args_arr), exec_builtin_cmd(ast, info));
	cmd_path = find_cmd_path(args_arr[0], info);
	if (!cmd_path)
	{
		ft_dprintf("minishell: %s: command not found\n", args_arr[0]);
		free_paths(args_arr);
		return (EXIT_CMD_NOT_FOUND);
	}
	free_paths(args_arr);
	return (exec_ext_cmd(ast, info, cmd_path));
}

/*** @brief Execute a simple command (builtin or external)*/
int	exec_simple_cmd(t_ast *ast, t_info *info)
{
	char	**args_arr;

	if (!ast->args)
	{
		if (ast->start_redirs || ast->redirs)
			return (exec_builtin_with_redir(ast, info));
		return (0);
	}
	args_arr = args_to_array(ast->args, info);
	if (!args_arr || !args_arr[0])
	{
		if (ast->start_redirs || ast->redirs)
			return (free_paths(args_arr), exec_builtin_with_redir(ast, info));
		return (free_paths(args_arr), 0);
	}
	return (exec_with_args(ast, info, args_arr));
}
