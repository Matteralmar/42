/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivantso <vivantso@student.42prague.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:54:16 by vivantso          #+#    #+#             */
/*   Updated: 2026/01/08 14:54:16 by vivantso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Handle child process wait and signal restoration
 * @return Exit status of the child process
 */
int	wait_and_cleanup(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT && !g_heredoc_sig)
		write(1, "\n", 1);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
		write(1, "Quit (core dumped)\n", 20);
	sig_recv();
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}

/**
 * @brief Fork error handler
 * @return Always returns 1 (error status)
 */
int	handle_fork_error(void)
{
	sig_recv();
	ft_dprintf("minishell: fork: %s\n", strerror(errno));
	return (1);
}
