#include "minishell.h"

/*** @brief This function checks for parantheses errors*/
int	paren_err(t_tokens *tokens)
{
	if ((tokens->type == WORD_TOKEN && tokens->next->type == PAREN_L_TOKEN)
		|| (tokens->type == PAREN_R_TOKEN
			&& (tokens->next->type == WORD_TOKEN
				|| tokens->next->type == PAREN_L_TOKEN))
		|| (tokens->next->type == PAREN_L_TOKEN
			&& (tokens->type >= REDIN_TOKEN
				&& tokens->type <= HEREDOC_TOKEN)))
		return (ft_dprintf("Unexpected parantheses error\n"), 1);
	if ((tokens->type == PAREN_L_TOKEN
			&& tokens->next->type != PAREN_L_TOKEN
			&& tokens->next->type != WORD_TOKEN
			&& !(tokens->next->type >= REDIN_TOKEN
				&& tokens->next->type <= HEREDOC_TOKEN))
		|| (tokens->type == PAREN_L_TOKEN
			&& tokens->next->type == PAREN_L_TOKEN
			&& (tokens->next->next->type >= REDIN_TOKEN
				&& tokens->next->next->type <= HEREDOC_TOKEN)))
		return (ft_dprintf("Unexpected parantheses error\n"), 1);
	return (0);
}
