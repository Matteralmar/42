#include "minishell.h"

/*** @brief This function checks to handle $ and * cases*/
int	handle_dollar_star(char *input, size_t *i, int *dollar)
{
	if (*i && input[*i - 1] == '$' && (input[*i] == '?' || input[*i] == '*'
			|| ft_isdigit(input[*i])))
	{
		(*i)++;
		return (1);
	}
	if (!*dollar && input[*i] == '$')
	{
		*dollar = 1;
		return (1);
	}
	return (0);
}

/*** @brief This function initializes the word part*/
void	init_word_part(t_word_part *wp, t_quote q_type, char *text)
{
	wp->text = NULL;
	wp->expand = FALSE;
	if (text[0] == '$' || text[0] == '*')
	{
		if (text[0] == '$' && (q_type == DOUBLE_QUOTE || q_type == NO_QUOTE))
			wp->expand = TRUE;
		if (text[0] == '*' && q_type == NO_QUOTE)
			wp->expand = TRUE;
	}
}
