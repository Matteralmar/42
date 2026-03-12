#include "minishell.h"

/*** @brief This function checks if prantheses are at there right place*/
static int	check_paren(t_tokens *tokens, int lparen)
{
	while (tokens && tokens->type != EOF_TOKEN)
	{
		if (tokens->type == PAREN_L_TOKEN)
			lparen++;
		if (paren_err(tokens))
			return (1);
		if (tokens->type == PAREN_R_TOKEN)
		{
			if (lparen == 0)
				return (ft_dprintf("Unexpected open parantheses ')'\n"), 1);
			lparen--;
		}
		tokens = tokens->next;
	}
	if (lparen > 0)
		return (ft_dprintf("Unclosed parantheses error '('\n"), 1);
	return (0);
}

/*** @brief This function processes redirects, commands
 * and subshells*/
static t_ast	*parse(t_tokens **tokens)
{
	t_redir	*start_redirs;

	start_redirs = NULL;
	if (*tokens && ((*tokens)->type >= REDIN_TOKEN
			&& (*tokens)->type <= HEREDOC_TOKEN))
	{
		start_redirs = redirs(tokens, -1);
		if (!start_redirs)
			return (NULL);
	}
	if ((*tokens)->type == PAREN_L_TOKEN)
		return (subshell(tokens, start_redirs));
	else
		return (cmd(tokens, start_redirs, -1, NULL));
}

/*** @brief This function goes left creating subtree of pipe branches*/
static t_ast	*parse_pipe(t_tokens **tokens)
{
	t_ast	*node;
	t_ast	*left;
	t_ast	*right;

	left = parse(tokens);
	if (!left)
		return (NULL);
	while (*tokens && (*tokens)->type == PIPE_TOKEN)
	{
		node = new_node(AST_PIPE, NULL);
		if (!node)
			return (free_ast(left), NULL);
		next_token(tokens);
		right = parse(tokens);
		if (!right)
			return (free_ast(left), free_ast(node), NULL);
		node->right = right;
		node->left = left;
		left = node;
	}
	return (left);
}

/*** @brief This function creates main ast tree. Treats each
 * new || or && as new top ast node*/
t_ast	*parser(t_tokens **tokens)
{
	t_ast	*node;
	t_ast	*left;
	t_ast	*right;

	left = parse_pipe(tokens);
	if (!left)
		return (NULL);
	while (*tokens && ((*tokens)->type == OR_TOKEN
			|| (*tokens)->type == AND_TOKEN))
	{
		if ((*tokens)->type == OR_TOKEN)
			node = new_node(AST_OR, NULL);
		else
			node = new_node(AST_AND, NULL);
		if (!node)
			return (free_ast(left), NULL);
		next_token(tokens);
		right = parse_pipe(tokens);
		if (!right)
			return (free_ast(left), free_ast(node), NULL);
		node->right = right;
		node->left = left;
		left = node;
	}
	return (left);
}

/*** @brief Such name is used because shell uses programs 
 * like lex and yacc to parse input*/
t_ast	*yacc(t_tokens **tokens)
{
	t_ast	*ast_tree;

	if (check_oper(*tokens, 1) || check_paren(*tokens, 0)
		|| check_redir(*tokens))
		return (NULL);
	ast_tree = parser(tokens);
	return (ast_tree);
}
