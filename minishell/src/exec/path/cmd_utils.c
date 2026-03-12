#include "minishell.h"
#include <sys/stat.h>

/*** @brief Execute builtin command with redirections*/
int	exec_builtin_with_redir(t_ast *ast, t_info *info)
{
	int		saved_fds[2];
	int		status;
	char	**args_arr;
	pid_t	pid;

	save_std_fds(saved_fds);
	args_arr = args_to_array(ast->args, info);
	if (ast->start_redirs || ast->redirs)
	{
		sig_ignore_int_quit();
		pid = fork();
		if (pid == 0)
			fork_builtin_child(ast, info, args_arr);
		status = wait_builtin_child(pid);
	}
	else if (!args_arr || !args_arr[0])
		status = 0;
	else
		status = exec_builtin(args_arr, info);
	restore_fds_and_cleanup(saved_fds, args_arr);
	return (status);
}

/*** @brief Execute external command in a child process*/
int	exec_external_cmd(t_ast *ast, t_info *info, char *cmd_path,
		char **args_arr)
{
	pid_t	pid;

	sig_ignore_int_quit();
	pid = fork();
	if (pid < 0)
		return (handle_fork_error());
	if (pid == 0)
		exec_child(ast, info, cmd_path, args_arr);
	return (wait_and_cleanup(pid));
}
