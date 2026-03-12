#include "minishell.h"

/*** @brief This function creates subshell node and
 * initializes its values*/
t_ast	*subshell(t_tokens **tokens, t_redir *start_redirs)
{
	t_ast	*subshell;
	t_ast	*subtree;

	next_token(tokens);
	subtree = parser(tokens);
	if (!subtree)
		return (ft_dprintf("Parsing subshell failed\n"), NULL);
	next_token(tokens);
	subshell = new_node(AST_SUBSHELL, NULL);
	if (!subshell)
		return (ft_dprintf("Malloc allocation for subshell failed\n"), NULL);
	subshell->left = subtree;
	subshell->start_redirs = start_redirs;
	if (*tokens && (*tokens)->type >= REDIN_TOKEN
		&& (*tokens)->type <= HEREDOC_TOKEN)
		ft_addback_redir(&subshell->redirs, redirs(tokens, -1));
	else
		subshell->redirs = NULL;
	return (subshell);
}

/*** @brief This function creates arg node*/
t_arg	*new_arg(void)
{
	t_arg	*arg;

	arg = malloc(sizeof(t_arg));
	if (!arg)
		return (ft_dprintf("Malloc allocation for args failed\n"), NULL);
	arg->word_parts = NULL;
	arg->next = NULL;
	return (arg);
}

/*** @brief This function adds arg node to the linked list of args*/
void	ft_addback_arg(t_arg **lst, t_arg *new)
{
	t_arg	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

/*** @brief This function handles redirection of fd*/
static int	handle_redirection(t_tokens **tokens, t_ast *cmd, int *fd)
{
	t_redir	*redir;

	if ((*tokens)->type == WORD_TOKEN
		&& (*tokens)->next
		&& ((*tokens)->next->type == REDOUT_TOKEN
			|| (*tokens)->next->type == REDAPP_TOKEN))
	{
		if ((*tokens)->text[0] >= '0' && (*tokens)->text[0] <= '2'
			&& (*tokens)->text[1] == '\0')
		{
			*fd = (*tokens)->text[0] - '0';
			next_token(tokens);
		}
	}
	if ((*tokens)->type >= REDIN_TOKEN && (*tokens)->type <= HEREDOC_TOKEN)
	{
		redir = redirs(tokens, *fd);
		if (!redir)
			return (0);
		ft_addback_redir(&cmd->redirs, redir);
		*fd = -1;
	}
	return (1);
}

/*** @brief This function creates command node and
 * initializes its values*/
t_ast	*cmd(t_tokens **tokens, t_redir *start_redirs, int fd, t_arg *curr_arg)
{
	t_ast	*cmd;

	cmd = new_node(AST_COMMAND, start_redirs);
	if (!cmd)
		return (NULL);
	while (((*tokens)->type == WORD_TOKEN || ((*tokens)->type >= REDIN_TOKEN
				&& (*tokens)->type <= HEREDOC_TOKEN)) && *tokens)
	{
		if (!handle_redirection(tokens, cmd, &fd))
			return (free_cmd(cmd), NULL);
		while (*tokens && (*tokens)->type == WORD_TOKEN)
		{
			if (is_fd_before_redir(*tokens))
				break ;
			if (process_argument(cmd, &curr_arg, *tokens))
				return (free_cmd(cmd), NULL);
			if (handle_split(tokens, &curr_arg))
				break ;
			next_token(tokens);
		}
	}
	return (cmd);
}
