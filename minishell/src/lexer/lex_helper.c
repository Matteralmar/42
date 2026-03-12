#include "minishell.h"

/*** @brief This function checks for the start of a token*/
int	is_token(char ch)
{
	if (ch == '&' || ch == '|' || ch == '>'
		|| ch == '<' || ch == ')' || ch == '(')
		return (1);
	else
		return (0);
}

/*** @brief This function adds token to the back of linked list 
 * if head is already there*/
static void	ft_addback_tokn(t_tokens **lst, t_tokens *new)
{
	t_tokens	*last;

	if (!lst || !new)
		return ;
	new->next = NULL;
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

/*** @brief This function clears linked list of tokens*/
void	ft_lstclr_tokns(t_tokens **lst)
{
	t_tokens	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->text);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

/*** @brief This function creates token node*/
int	create_token(t_tokens **tokens,
t_tokens_type token_type, t_quote quote_type, char *text)
{
	t_tokens	*tokn;

	tokn = malloc(sizeof(t_tokens));
	if (!tokn)
		return (ft_dprintf("minishell: malloc failed\n"), 1);
	tokn->text = text;
	tokn->type = token_type;
	tokn->q_type = quote_type;
	tokn->word_join = SPLIT;
	tokn->next = NULL;
	if (!*tokens)
		*tokens = tokn;
	else
		ft_addback_tokn(tokens, tokn);
	return (0);
}

/*** @brief This function identifies operators and invalid tokens*/
t_tokens_type	check_operator(const char *input, size_t *i)
{
	if (input[*i] == '<' && input[*i + 1] == '<'
		&& !is_invalid_next(input, *i + 2))
		return (*i += 2, HEREDOC_TOKEN);
	else if (input[*i] == '>' && input[*i + 1] == '>'
		&& !is_invalid_next(input, *i + 2))
		return (*i += 2, REDAPP_TOKEN);
	else if (input[*i] == '&' && input[*i + 1] == '&'
		&& !is_invalid_next(input, *i + 2))
		return (*i += 2, AND_TOKEN);
	else if (input[*i] == '|' && input[*i + 1] == '|'
		&& !is_invalid_next(input, *i + 2))
		return (*i += 2, OR_TOKEN);
	else if (input[*i] == '|' && !is_invalid_next(input, *i + 1))
		return (*i += 1, PIPE_TOKEN);
	else if (input[*i] == '<' && !is_invalid_next(input, *i + 1))
		return (*i += 1, REDIN_TOKEN);
	else if (input[*i] == '>' && !is_invalid_next(input, *i + 1))
		return (*i += 1, REDOUT_TOKEN);
	else if (input[*i] == '(' && !is_invalid_next(input, *i + 1))
		return (*i += 1, PAREN_L_TOKEN);
	else if (input[*i] == ')' && !is_invalid_next(input, *i + 1))
		return (*i += 1, PAREN_R_TOKEN);
	return (INVALID_TOKEN);
}
