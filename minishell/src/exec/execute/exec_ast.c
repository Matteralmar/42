#include "minishell.h"

/*** @brief Apply non-heredoc redirections*/
static int	apply_other_redirs(t_redir *redirs)
{
	t_redir	*curr;

	curr = redirs;
	while (curr)
	{
		if (curr->type == AST_REDIR_IN && handle_redir_in(curr) < 0)
			return (-1);
		else if (curr->type == AST_REDIR_OUT && handle_redir_out(curr) < 0)
			return (-1);
		else if (curr->type == AST_REDIR_APPEND
			&& handle_redir_append(curr) < 0)
			return (-1);
		curr = curr->next;
	}
	return (0);
}

/*** @brief Setup all redirections for a command*/
int	setup_redirections(t_redir *redirs, t_info *info)
{
	t_redir	*last_heredoc;
	t_redir	*curr;

	last_heredoc = NULL;
	curr = redirs;
	while (curr)
	{
		if (curr->type == AST_HEREDOC)
		{
			if (curr->fd < 0 && handle_heredoc(curr, info) < 0)
				return (-1);
			if (last_heredoc && last_heredoc->fd >= 0)
				close(last_heredoc->fd);
			last_heredoc = curr;
		}
		curr = curr->next;
	}
	if (last_heredoc && last_heredoc->fd >= 0)
	{
		dup2(last_heredoc->fd, STDIN_FILENO);
		close(last_heredoc->fd);
	}
	return (apply_other_redirs(redirs));
}

/*** @brief Execute logical operators (AND, OR)*/
static int	exec_logical(t_ast *ast, t_info *info)
{
	int	left_status;

	left_status = exec_ast(ast->left, info);
	if (ast->type == AST_AND)
	{
		if (left_status == 0)
			return (exec_ast(ast->right, info));
		return (left_status);
	}
	else if (ast->type == AST_OR)
	{
		if (left_status != 0)
			return (exec_ast(ast->right, info));
		return (left_status);
	}
	return (1);
}

/*** @brief Execute subshell command*/
static int	exec_subshell(t_ast *ast, t_info *info)
{
	pid_t	pid;
	int		status;

	sig_ignore_int_quit();
	pid = fork();
	if (pid < 0)
		return (sig_recv(), ft_dprintf("minishell: fork: %s\n",
				strerror(errno)), 1);
	if (pid == 0)
	{
		sig_init_child();
		if (setup_redirections(ast->redirs, info) < 0)
			exit(1);
		exit(exec_ast(ast->left, info));
	}
	if (ast->redirs)
		return (exec_builtin_with_redir(ast, info));
	waitpid(pid, &status, 0);
	sig_recv();
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (EXIT_SIGNAL_BASE + WTERMSIG(status));
	return (EXIT_GENERAL_ERROR);
}

/*** @brief Main AST execution dispatcher*/
int	exec_ast(t_ast *ast, t_info *info)
{
	if (!ast)
		return (0);
	if (ast->type == AST_COMMAND)
		return (exec_simple_cmd(ast, info));
	else if (ast->type == AST_PIPE)
		return (exec_pipeline(ast, info));
	else if (ast->type == AST_AND || ast->type == AST_OR)
		return (exec_logical(ast, info));
	else if (ast->type == AST_SUBSHELL)
		return (exec_subshell(ast, info));
	return (0);
}
