#include "minishell.h"

/*** @brief Generate unique filename for heredoc temporary file*/
char	*generate_heredoc_filename(void)
{
	static int	counter = 0;
	char		*counter_str;
	char		*filename;

	counter_str = ft_itoa(counter++);
	filename = ft_strjoin("/tmp/.heredoc_", counter_str);
	free(counter_str);
	return (filename);
}

/*** @brief Read heredoc input using child process*/
int	read_heredoc(char *delimiter, t_bool expand, t_info *info)
{
	int	pid;
	int	pipe_fd[2];
	int	fd;

	if (pipe(pipe_fd) == -1)
		return (sig_recv(), -1);
	pid = fork();
	if (pid < 0)
		return (close(pipe_fd[0]), close(pipe_fd[1]), sig_recv(), -1);
	if (pid == 0)
		heredoc_child(pipe_fd, delimiter, expand, info);
	sig_ignore_int_quit();
	fd = wait_heredoc_child(pid, pipe_fd);
	sig_recv();
	if (fd < 0)
	{
		info->last_exit_status = EXIT_SIGINT;
		g_heredoc_sig = 1;
	}
	return (fd);
}

/*** @brief Handle heredoc redirection (<<)*/
int	handle_heredoc(t_redir *curr, t_info *info)
{
	int		pipe_fd;
	char	*delimiter;
	t_bool	expand;

	delimiter = join_and_trim_parts(curr->filename_parts);
	if (!delimiter)
		return (-1);
	expand = should_expand_heredoc(curr->filename_parts);
	pipe_fd = read_heredoc(delimiter, expand, info);
	free(delimiter);
	if (pipe_fd < 0)
		return (-1);
	curr->fd = pipe_fd;
	return (0);
}
