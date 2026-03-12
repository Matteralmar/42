#include "minishell.h"

/*** @brief This function goes through list of tokens*/
void	next_token(t_tokens **tokens)
{
	if ((*tokens)->next)
		*tokens = (*tokens)->next;
}

/*** @brief This function creates new ast node*/
t_ast	*new_node(t_ast_type type, t_redir *start_redir)
{
	t_ast	*new;

	new = malloc(sizeof(t_ast));
	if (!new)
		return (ft_dprintf("Malloc allocatoin for ast node failed\n"), NULL);
	new->type = type;
	new->args = NULL;
	new->redirs = NULL;
	new->start_redirs = start_redir;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/*** @brief This function frees newly allocated command node*/
void	free_cmd(t_ast *cmd)
{
	if (!cmd)
		return ;
	free_redirs(cmd->redirs);
	cmd->redirs = NULL;
	free_redirs(cmd->start_redirs);
	cmd->start_redirs = NULL;
	free_args(cmd->args);
	cmd->args = NULL;
	free(cmd);
}

/*** @brief This function checks if argument node is created
 * and adds it to list of ast args*/
int	handle_new_arg(t_ast *cmd, t_arg **curr_arg)
{
	if (!*curr_arg)
	{
		*curr_arg = new_arg();
		if (!*curr_arg)
			return (1);
		ft_addback_arg(&cmd->args, *curr_arg);
	}
	return (0);
}

/*** @brief This function checks if next argument is split
 * with current argument*/
int	handle_split(t_tokens **tokens, t_arg **curr_arg)
{
	if ((*tokens)->word_join == SPLIT)
	{
		next_token(tokens);
		*curr_arg = NULL;
		return (1);
	}
	return (0);
}
