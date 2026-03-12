#include "../../include/minishell.h"

/*** @brief This function parses input then executes it*/
static void	process_input(char *input, t_info *info)
{
	t_tokens	*tokens;
	int			status;

	info->tokens = lex(0, input);
	tokens = info->tokens;
	if (!tokens)
	{
		update_last_status(info, EXIT_MISUSE);
		return ;
	}
	free(input);
	info->ast = yacc(&info->tokens);
	if (!info->ast)
	{
		ft_lstclr_tokns(&tokens);
		update_last_status(info, EXIT_MISUSE);
		info->tokens = NULL;
		return ;
	}
	status = exec_ast(info->ast, info);
	update_last_status(info, status);
	ft_lstclr_tokns(&tokens);
	info->tokens = NULL;
	free_ast(info->ast);
	info->ast = NULL;
}

/*** @brief This is read-process loop function*/
static void	run_shell(t_info *info)
{
	char	*input;

	while (1)
	{
		if (g_heredoc_sig)
		{
			update_last_status(info, EXIT_SIGINT);
			g_heredoc_sig = 0;
			continue ;
		}
		input = readline("➜ minishell> ");
		if (!input)
		{
			update_last_status(info, EXIT_SIGINT);
			break ;
		}
		if (*input)
		{
			if (info->interactive)
				add_history(input);
			process_input(input, info);
		}
		else
			free(input);
	}
}

/*** @brief This is the main function of minishell project*/
int	main(int argc, char **argv, char **env)
{
	t_info	*info;

	if (argc != 1 || !argv[0])
		return (ft_dprintf("minishell: invalid arguments\n"), EXIT_MISUSE);
	info = init_info();
	if (!info)
		return (ft_dprintf("minishell: failed to allocate info\n"),
			EXIT_GENERAL_ERROR);
	if (init_env(env, info))
		return (ft_dprintf("minishell: failed to allocate env\n"),
			free_ll(info), EXIT_GENERAL_ERROR);
	sig_recv();
	info->interactive = isatty(STDIN_FILENO);
	run_shell(info);
	if (info->interactive)
		ft_printf("exit\n");
	free_ll(info);
	return (EXIT_SUCCESS);
}
