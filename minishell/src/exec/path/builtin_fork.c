#include "minishell.h"

/*** @brief Wait for builtin child process*/
int	wait_builtin_child(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	sig_recv();
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

/*** @brief Fork and execute builtin in child*/
void	fork_builtin_child(t_ast *ast, t_info *info, char **args_arr)
{
	int	status;

	sig_init_child();
	if (setup_redirections(ast->start_redirs, info) < 0
		|| setup_redirections(ast->redirs, info) < 0)
		exit(1);
	if (!args_arr || !args_arr[0])
		exit(0);
	status = exec_builtin(args_arr, info);
	free_paths(args_arr);
	exit(status);
}
