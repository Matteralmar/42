#include "minishell.h"

/**
 * @brief Restore saved file descriptors and free args
 */
void	restore_fds_and_cleanup(int saved_fds[2], char **args_arr)
{
	free_paths(args_arr);
	dup2(saved_fds[0], STDIN_FILENO);
	dup2(saved_fds[1], STDOUT_FILENO);
	close(saved_fds[0]);
	close(saved_fds[1]);
}

/**
 * @brief Save standard input and output file descriptors
 */
void	save_std_fds(int saved_fds[2])
{
	saved_fds[0] = dup(STDIN_FILENO);
	saved_fds[1] = dup(STDOUT_FILENO);
}
