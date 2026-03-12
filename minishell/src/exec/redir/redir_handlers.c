#include "minishell.h"

/*** @brief Join text parts and trim (without expansion)*/
char	*join_and_trim_parts(t_word_part *parts)
{
	char		*result;
	char		*temp;
	char		*trimmed;
	t_word_part	*curr;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	curr = parts;
	while (curr)
	{
		if (curr->text && *curr->text)
		{
			temp = ft_strjoin(result, curr->text);
			free(result);
			if (!temp)
				return (NULL);
			result = temp;
		}
		curr = curr->next;
	}
	trimmed = ft_strtrim(result, " \t\n\r");
	free(result);
	return (trimmed);
}

/*** @brief Handle input redirection (<)*/
int	handle_redir_in(t_redir *curr)
{
	char	*filename;
	int		fd;
	int		target_fd;

	filename = join_and_trim_parts(curr->filename_parts);
	if (!filename)
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_dprintf("%s: %s\n", filename, strerror(errno));
		free(filename);
		return (-1);
	}
	free(filename);
	target_fd = STDIN_FILENO;
	if (curr->fd >= 0)
		target_fd = curr->fd;
	dup2(fd, target_fd);
	close(fd);
	return (0);
}

/*** @brief Handle output redirection (>)*/
int	handle_redir_out(t_redir *curr)
{
	char	*filename;
	int		fd;
	int		target_fd;

	filename = join_and_trim_parts(curr->filename_parts);
	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_dprintf("%s: %s\n", filename, strerror(errno));
		free(filename);
		return (-1);
	}
	free(filename);
	target_fd = STDOUT_FILENO;
	if (curr->fd >= 0)
		target_fd = curr->fd;
	dup2(fd, target_fd);
	close(fd);
	return (0);
}

/*** @brief Handle append redirection (>>)*/
int	handle_redir_append(t_redir *curr)
{
	char	*filename;
	int		fd;
	int		target_fd;

	filename = join_and_trim_parts(curr->filename_parts);
	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		ft_dprintf("%s: %s\n", filename, strerror(errno));
		free(filename);
		return (-1);
	}
	free(filename);
	target_fd = STDOUT_FILENO;
	if (curr->fd >= 0)
		target_fd = curr->fd;
	dup2(fd, target_fd);
	close(fd);
	return (0);
}
