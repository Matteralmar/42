#include "minishell.h"

/*** @brief This function checks an edge case of fd redirections*/
int	is_fd_before_redir(t_tokens *tok)
{
	if (!tok || !tok->next)
		return (0);
	if (tok->text[0] >= '0' && tok->text[0] <= '2' && tok->text[1] == '\0')
	{
		if (tok->next->type == REDOUT_TOKEN
			|| tok->next->type == REDAPP_TOKEN)
			return (1);
	}
	return (0);
}

/*** @brief This function processes argument linked list*/
int	process_argument(t_ast *cmd, t_arg **curr_arg, t_tokens *tokens)
{
	if (handle_new_arg(cmd, curr_arg))
		return (1);
	if (make_words(&(*curr_arg)->word_parts,
			tokens->q_type, tokens->text, tokens->word_join))
		return (1);
	return (0);
}

/*** @brief This function decides if it is a split between words or not*/
t_split_join	word_join_or_split(char ch)
{
	if (ch == ' ' || (ch >= 9 && ch <= 13) || is_token(ch) || !ch)
		return (SPLIT);
	return (JOIN);
}

/*** @brief This function goes to the currently last word token 
 * and adds split or join quality to it */
void	join_or_split(t_tokens **tokens, t_split_join split_join)
{
	t_tokens	*lst;

	lst = *tokens;
	while (lst->next)
		lst = lst->next;
	lst->word_join = split_join;
}

/*** @brief This function checks if there are any other symbols
 *  after correct set of operators*/
int	is_invalid_next(const char *input, size_t i)
{
	char	ch;

	ch = input[i];
	if (!ch)
		return (0);
	if (ft_strchr("\\;", ch))
		return (1);
	return (0);
}
