#include "minishell.h"

/*** @brief Write one line to heredoc*/
static void	write_line_to_fd(int fd, char *line, t_bool expand, t_info *info)
{
	char	*expanded;

	if (expand)
	{
		expanded = expand_variables_in_text(line, info);
		write(fd, expanded, ft_strlen(expanded));
		free(expanded);
	}
	else
		write(fd, line, ft_strlen(line));
	write(fd, "\n", 1);
}

/*** @brief Write heredoc lines until delimiter is found*/
void	write_heredoc_lines(int fd, char *delimiter, t_bool expand,
		t_info *info)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (g_heredoc_sig)
				exit(EXIT_SIGINT);
			break ;
		}
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
			break ;
		write_line_to_fd(fd, line, expand, info);
		free(line);
	}
	free(line);
}

/*** @brief Heredoc child process*/
void	heredoc_child(int *pipe_fd, char *delim, t_bool exp, t_info *info)
{
	sig_init_heredoc();
	close(pipe_fd[0]);
	write_heredoc_lines(pipe_fd[1], delim, exp, info);
	close(pipe_fd[1]);
	exit(EXIT_SUCCESS);
}
