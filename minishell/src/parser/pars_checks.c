#include "minishell.h"

/*** @brief This function checks if tokens are not at the beginning of string*/
static int	check_frst_tkn(t_tokens *tokens)
{
	if (tokens->type == PIPE_TOKEN)
		return (ft_dprintf("Unexpected token/syntax error '|'\n"), 1);
	if (tokens->type == AND_TOKEN)
		return (ft_dprintf("Unexpected token/syntax error '&&'\n"), 1);
	if (tokens->type == OR_TOKEN)
		return (ft_dprintf("Unexpected token/syntax error '||'\n"), 1);
	return (0);
}

/*** @brief This function checks if tokens are not at the end of string*/
static int	check_lst_tkn(t_tokens *tokens)
{
	if (tokens->type == PIPE_TOKEN)
		return (ft_dprintf("Unexpected token/syntax error '|'\n"), 1);
	if (tokens->type == AND_TOKEN)
		return (ft_dprintf("Unexpected token/syntax error '&&'\n"), 1);
	if (tokens->type == OR_TOKEN)
		return (ft_dprintf("Unexpected token/syntax error '||'\n"), 1);
	if (tokens->type == REDOUT_TOKEN || tokens->type == REDIN_TOKEN
		|| tokens->type == REDAPP_TOKEN)
	{
		if (tokens->next->type == PAREN_R_TOKEN)
			return (ft_dprintf("Unexpected token/syntax error ')'\n"), 1);
		if (tokens->next->type == EOF_TOKEN)
			return (ft_dprintf("Unexpected token/syntax error 'newline'\n"), 1);
	}
	return (0);
}

/*** @brief This function checks if tokens are not sequentially written*/
static int	check_chained_oper(t_tokens *tokens)
{
	if (tokens->next->type == PIPE_TOKEN)
		return (ft_dprintf("Unexpected token/syntax error '|'\n"), 1);
	if (tokens->next->type == AND_TOKEN)
		return (ft_dprintf("Unexpected token/syntax error '&&'\n"), 1);
	if (tokens->next->type == OR_TOKEN)
		return (ft_dprintf("Unexpected token/syntax error '||'\n"), 1);
	return (0);
}

/*** @brief This function checks if tokens are at there right place*/
int	check_oper(t_tokens *tokens, int start)
{
	while (tokens && tokens->type != EOF_TOKEN)
	{
		while (start && tokens->type == PAREN_L_TOKEN)
			tokens = tokens->next;
		if (start && check_frst_tkn(tokens))
			return (1);
		if (tokens->type == PAREN_L_TOKEN)
			tokens = tokens->next;
		if ((tokens->next
				&& (tokens->next->type == PAREN_R_TOKEN
					|| tokens->next->type == EOF_TOKEN)
				&& check_lst_tkn(tokens))
			|| ((tokens->type == PIPE_TOKEN
					|| tokens->type == AND_TOKEN
					|| tokens->type == OR_TOKEN)
				&& check_chained_oper(tokens)))
			return (1);
		start = 0;
		tokens = tokens->next;
	}
	return (0);
}

/*** @brief This function checks if redirect is valid in line*/
int	check_redir(t_tokens *tokens)
{
	while (tokens && tokens->type != EOF_TOKEN)
	{
		if (tokens->type >= REDIN_TOKEN && tokens->type <= HEREDOC_TOKEN)
		{
			if (tokens->next->type == PIPE_TOKEN)
				return (ft_dprintf("Unexpected token/syntax error '|'\n"), 1);
			if (tokens->next->type == AND_TOKEN)
				return (ft_dprintf("Unexpected token/syntax error '&&'\n"), 1);
			if (tokens->next->type == OR_TOKEN)
				return (ft_dprintf("Unexpected token/syntax error '||'\n"), 1);
			if (tokens->next->type == EOF_TOKEN)
				return (ft_dprintf("Unexpected token/syntax error 'newline'\n"),
					1);
			if (tokens->next->type == PAREN_R_TOKEN)
				return (ft_dprintf("Unexpected token/syntax error ')'\n"), 1);
		}
		tokens = tokens->next;
	}
	return (0);
}
