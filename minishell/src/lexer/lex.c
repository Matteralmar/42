#include "minishell.h"

/*** @brief This function checks qouted command string and returns word*/
static char	*quoted_txt(size_t *i, char *input, char qt)
{
	char	*text;
	size_t	st;
	size_t	len;

	st = *i + 1;
	(*i)++;
	while (input[*i] && input[*i] != qt)
		(*i)++;
	if (input[*i] != qt)
		return (ft_dprintf("minishell: syntax error: unclosed quotes\n"), NULL);
	len = *i - st;
	text = malloc(*i - st + 1);
	(*i)++;
	if (!text)
		return (ft_dprintf("minishell: malloc failed\n"), NULL);
	ft_memcpy(text, &input[st], len);
	text[len] = '\0';
	return (text);
}

/*** @brief This function checks unqouted command string and returns word*/
static char	*nquoted_txt(size_t *i, char *input, int dollar)
{
	char	*text;
	size_t	st;

	st = *i;
	text = NULL;
	while (input[*i]
		&& !(input[*i] == ' ' || (input[*i] >= 9 && input[*i] <= 13))
		&& input[*i] != '"'
		&& input[*i] != '\''
		&& !is_token(input[*i]))
	{
		if (input[*i] == ';' || input[*i] == '\\')
			return (ft_printf(
					"minishell: syntax error near unexpected token `%c'\n",
					input[*i]), NULL);
		(*i)++;
		if (handle_dollar_star(input, i, &dollar))
			break ;
	}
	text = malloc(*i - st + 1);
	if (!text)
		return (ft_dprintf("minishell: malloc failed\n"), NULL);
	ft_memcpy(text, &input[st], *i - st);
	text[*i - st] = '\0';
	return (text);
}

/*** @brief This function creates an operator token*/
static int	tokenize_operator(char *input, t_tokens **tokens, size_t *i)
{
	int				chk;
	t_tokens_type	type;

	type = check_operator(input, i);
	if (type == INVALID_TOKEN)
		return (ft_dprintf("minishell: syntax error: unexpected token\n"), 1);
	chk = create_token(tokens, type, NO_QUOTE, NULL);
	if (chk)
		return (1);
	join_or_split(tokens, SPLIT);
	return (0);
}

/*** @brief This function creates a word token which can be quoted or unquoted*/
static int	tokenize_command(char *input, t_tokens **tokens, size_t *i)
{
	t_quote			type;
	int				chk;
	char			*text;
	t_split_join	split_join;

	if (input[*i] == '\'')
		type = SINGLE_QUOTE;
	else if (input[*i] == '"')
		type = DOUBLE_QUOTE;
	else
		type = NO_QUOTE;
	if (type == SINGLE_QUOTE || type == DOUBLE_QUOTE)
		text = quoted_txt(i, input, input[*i]);
	else
		text = nquoted_txt(i, input, 0);
	if (!text)
		return (1);
	split_join = word_join_or_split(input[*i]);
	chk = create_token(tokens, WORD_TOKEN, type, text);
	if (chk)
		return (free(text), 1);
	join_or_split(tokens, split_join);
	return (0);
}

/*** @brief This function creates linked list of tokens 
 * which will be used later in parsing part*/
t_tokens	*lex(size_t i, char *input)
{
	t_tokens	*tokens;
	int			chk;

	tokens = NULL;
	while (input[i])
	{
		ft_skip_spaces(input, &i);
		if (!input[i])
			break ;
		if (is_token(input[i]))
		{
			if (tokenize_operator(input, &tokens, &i))
				return (ft_lstclr_tokns(&tokens), NULL);
		}
		else
		{
			if (tokenize_command(input, &tokens, &i))
				return (ft_lstclr_tokns(&tokens), NULL);
		}
	}
	chk = create_token(&tokens, EOF_TOKEN, NO_QUOTE, NULL);
	if (chk)
		return (ft_lstclr_tokns(&tokens), NULL);
	join_or_split(&tokens, SPLIT);
	return (tokens);
}
