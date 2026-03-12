#include "minishell.h"

/*** @brief Handle execve error*/
static void	handle_execve_error(char *cmd_path)
{
	if (errno == EACCES)
	{
		ft_dprintf("minishell: %s: %s\n", cmd_path, strerror(errno));
		exit(EXIT_CMD_NOT_EXEC);
	}
	ft_dprintf("minishell: %s: %s\n", cmd_path, strerror(errno));
	exit(EXIT_CMD_NOT_FOUND);
}

/*** @brief Execute command in child process*/
void	exec_child(t_ast *ast, t_info *info, char *cmd_path, char **args_arr)
{
	struct stat	st;

	sig_init_child();
	if (setup_redirections(ast->start_redirs, info) < 0
		|| setup_redirections(ast->redirs, info) < 0)
		exit(1);
	if (stat(cmd_path, &st) == 0 && S_ISDIR(st.st_mode))
	{
		ft_dprintf("minishell: %s: Is a directory\n", cmd_path);
		exit(EXIT_CMD_NOT_EXEC);
	}
	default_int_quit();
	execve(cmd_path, args_arr, info->envs->vars);
	handle_execve_error(cmd_path);
}
