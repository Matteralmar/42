#include "minishell.h"

/*** @brief This function collects all word parts into
 * word part linked list*/
int	make_words(t_word_part **first, t_quote q_type, char *text,
t_split_join split_join)
{
	t_word_part	*start;
	t_word_part	*new;

	new = malloc(sizeof(t_word_part));
	if (!new)
		return (ft_dprintf("minishell: malloc failed\n"), 1);
	if (!text)
		return (free(new),
			ft_dprintf("minishell: internal error: text is NULL\n"), 1);
	init_word_part(new, q_type, text);
	if (split_join == JOIN)
		new->text = ft_strdup(text);
	else
		new->text = ft_strjoin(text, " ");
	if (!new->text)
		return (free(new), ft_dprintf("minishell: malloc failed\n"), 1);
	new->q_type = q_type;
	new->next = NULL;
	if (!*first)
		return (*first = new, 0);
	start = *first;
	while (start->next)
		start = start->next;
	start->next = new;
	return (0);
}

/*** @brief This function frees all word parts*/
void	free_word_parts(t_word_part *p)
{
	t_word_part	*tmp;

	while (p)
	{
		tmp = p->next;
		free(p->text);
		free(p);
		p = tmp;
	}
}

/*** @brief This function initializes redir node and
 * collects word parts for redir filename*/
static t_redir	*parse_redirs(t_tokens **tokens, int fd)
{
	t_redir	*redirs;

	redirs = malloc(sizeof(t_redir));
	if (!redirs)
		return (ft_dprintf("Malloc allocation for redirect failed\n"), NULL);
	redirs->type = (int)(*tokens)->type;
	redirs->fd = fd;
	redirs->filename_parts = NULL;
	redirs->next = NULL;
	next_token(tokens);
	if (!*tokens || (*tokens)->type != WORD_TOKEN)
		return (free(redirs),
			ft_dprintf("No filename or delimiter for redirection\n"), NULL);
	while (*tokens && (*tokens)->type == WORD_TOKEN)
	{
		if (make_words(&redirs->filename_parts,
				(*tokens)->q_type, (*tokens)->text, (*tokens)->word_join))
			return (free_word_parts(redirs->filename_parts),
				free(redirs), NULL);
		if ((*tokens)->word_join == SPLIT)
			return (next_token(tokens), redirs);
		next_token(tokens);
	}
	return (redirs);
}

/*** @brief This function adds redir node to redir linked list*/
void	ft_addback_redir(t_redir **lst, t_redir *new)
{
	t_redir	*last;

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

/*** @brief This function creates a linked list of redirs*/
t_redir	*redirs(t_tokens **tokens, int fd)
{
	t_redir	*redir;
	t_redir	*redirs;

	redirs = NULL;
	while (*tokens && ((*tokens)->type >= REDIN_TOKEN
			&& (*tokens)->type <= HEREDOC_TOKEN))
	{
		redir = parse_redirs(tokens, fd);
		fd = -1;
		if (!redir)
			return (ft_dprintf("Parsing redirections failed\n"), NULL);
		ft_addback_redir(&redirs, redir);
	}
	if (!redirs)
		next_token(tokens);
	return (redirs);
}
