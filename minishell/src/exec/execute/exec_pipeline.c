#include "minishell.h"

/*** @brief Fork and execute left side of pipeline*/
static pid_t	fork_left(t_ast *ast, t_info *info, int *pipefd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		sig_init_child();
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		exit(exec_ast(ast->left, info));
	}
	return (pid);
}

/*** @brief Fork and execute right side of pipeline*/
static pid_t	fork_right(t_ast *ast, t_info *info, int *pipefd)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		sig_init_child();
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		exit(exec_ast(ast->right, info));
	}
	return (pid);
}

static int	wait_pipeline(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (EXIT_SIGNAL_BASE + WTERMSIG(status));
	return (EXIT_GENERAL_ERROR);
}

static int	cleanup_and_wait(int *pipefd, pid_t pid_left, pid_t pid_right)
{
	int	status_left;
	int	status_right;
	int	sig_l;
	int	sig_r;

	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid_left, &status_left, 0);
	waitpid(pid_right, &status_right, 0);
	sig_l = WIFSIGNALED(status_left) && (WTERMSIG(status_left) == SIGINT
			|| WTERMSIG(status_left) == SIGPIPE);
	sig_r = WIFSIGNALED(status_right) && (WTERMSIG(status_right) == SIGINT
			|| WTERMSIG(status_right) == SIGPIPE);
	if ((sig_l || sig_r || WEXITSTATUS(status_left) == EXIT_SIGINT
			|| WEXITSTATUS(status_right) == EXIT_SIGINT) && !g_heredoc_sig)
		write(1, "\n", 1);
	if ((WIFSIGNALED(status_left) && WTERMSIG(status_left) == SIGQUIT)
		|| (WIFSIGNALED(status_right) && WTERMSIG(status_right) == SIGQUIT))
		write(1, "Quit (core dumped)\n", 20);
	sig_recv();
	return (wait_pipeline(status_right));
}

/*** @brief Execute pipeline command*/
int	exec_pipeline(t_ast *ast, t_info *info)
{
	int		pipefd[2];
	pid_t	pid_left;
	pid_t	pid_right;

	if (preprocess_heredocs(ast, info) < 0)
		return (EXIT_GENERAL_ERROR);
	if (pipe(pipefd) < 0)
		return (ft_dprintf("minishell: pipe: %s\n", strerror(errno)),
			EXIT_GENERAL_ERROR);
	sig_ignore_int_quit();
	pid_left = fork_left(ast, info, pipefd);
	if (pid_left < 0)
		return (sig_recv(), close(pipefd[0]), close(pipefd[1]),
			ft_dprintf("minishell: fork: %s\n", strerror(errno)),
			EXIT_GENERAL_ERROR);
	pid_right = fork_right(ast, info, pipefd);
	if (pid_right < 0)
	{
		waitpid(pid_left, NULL, 0);
		return (sig_recv(), close(pipefd[0]), close(pipefd[1]),
			ft_dprintf("minishell: fork: %s\n", strerror(errno)),
			EXIT_GENERAL_ERROR);
	}
	return (cleanup_and_wait(pipefd, pid_left, pid_right));
}
