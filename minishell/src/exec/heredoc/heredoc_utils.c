#include "minishell.h"

/*** @brief Wait for heredoc child and handle status*/
int	wait_heredoc_child(int pid, int pipe_fd[2])
{
	int	status;

	close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SIGINT)
	{
		close(pipe_fd[0]);
		return (-1);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_SUCCESS)
		return (pipe_fd[0]);
	close(pipe_fd[0]);
	return (-1);
}

/*** @brief Check if heredoc should expand variables based on delimiter quotes*/
t_bool	should_expand_heredoc(t_word_part *parts)
{
	t_word_part	*part;

	part = parts;
	while (part)
	{
		if (part->q_type != NO_QUOTE)
			return (FALSE);
		part = part->next;
	}
	return (TRUE);
}

/*** @brief Cleanup opened heredoc fds on error*/
void	cleanup_heredocs(t_redir *redirs, t_redir *failed)
{
	t_redir	*iter;

	iter = redirs;
	while (iter != failed)
	{
		if (iter->type == AST_HEREDOC && iter->fd >= 0)
			close(iter->fd);
		iter = iter->next;
	}
}

/*** @brief Process all heredocs and return last one*/
t_redir	*process_heredocs(t_redir *redirs, t_info *info)
{
	t_redir	*curr;
	t_redir	*last_heredoc;

	last_heredoc = NULL;
	curr = redirs;
	while (curr)
	{
		if (curr->type == AST_HEREDOC)
		{
			if (handle_heredoc(curr, info) < 0)
				return (cleanup_heredocs(redirs, curr), NULL);
			if (last_heredoc && last_heredoc->fd >= 0)
				close(last_heredoc->fd);
			last_heredoc = curr;
		}
		curr = curr->next;
	}
	return (last_heredoc);
}

/*** @brief Pre-process heredocs for an AST tree before execution*/
int	preprocess_heredocs(t_ast *ast, t_info *info)
{
	if (!ast)
		return (0);
	if (ast->type == AST_PIPE)
	{
		if (preprocess_heredocs(ast->left, info) < 0)
			return (-1);
		if (preprocess_heredocs(ast->right, info) < 0)
			return (-1);
		return (0);
	}
	if (ast->start_redirs && process_heredocs(ast->start_redirs, info) == NULL)
	{
		if (ast->start_redirs->type == AST_HEREDOC)
			return (-1);
	}
	if (ast->redirs && process_heredocs(ast->redirs, info) == NULL)
	{
		if (ast->redirs->type == AST_HEREDOC)
			return (-1);
	}
	return (0);
}
