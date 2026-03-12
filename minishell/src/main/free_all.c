#include "minishell.h"

/*** @brief This function frees envs that were used for this session*/
static void	free_env(t_env *env)
{
	size_t	i;

	if (!env)
		return ;
	if (env->vars)
	{
		i = 0;
		while (env->vars[i])
		{
			free(env->vars[i]);
			i++;
		}
		free(env->vars);
	}
	free(env);
}

/*** @brief This function frees argument linked list in ast node*/
void	free_args(t_arg *args)
{
	t_arg		*tmp_arg;
	t_word_part	*wp;
	t_word_part	*tmp_wp;

	while (args)
	{
		tmp_arg = args->next;
		wp = args->word_parts;
		while (wp)
		{
			tmp_wp = wp->next;
			free(wp->text);
			free(wp);
			wp = tmp_wp;
		}
		free(args);
		args = tmp_arg;
	}
}

/*** @brief This function frees redirection linked list in ast node*/
void	free_redirs(t_redir *redir)
{
	t_redir		*tmp_redir;
	t_word_part	*wp;
	t_word_part	*tmp_wp;

	while (redir)
	{
		tmp_redir = redir->next;
		wp = redir->filename_parts;
		while (wp)
		{
			tmp_wp = wp->next;
			if (wp->text)
				free(wp->text);
			free(wp);
			wp = tmp_wp;
		}
		free(redir);
		redir = tmp_redir;
	}
}

/*** @brief This function frees all nodes in ast tree*/
void	free_ast(t_ast *node)
{
	if (!node)
		return ;
	free_ast(node->left);
	free_ast(node->right);
	if (node->args)
		free_args(node->args);
	if (node->redirs)
		free_redirs(node->redirs);
	if (node->start_redirs)
		free_redirs(node->start_redirs);
	free(node);
}

/*** @brief This function frees all allocated memory 
 * left to free after exit*/
void	free_ll(t_info *info)
{
	if (!info)
		return ;
	if (info->tokens)
		ft_lstclr_tokns(&info->tokens);
	if (info->envs)
		free_env(info->envs);
	if (info->ast)
		free_ast(info->ast);
	free(info);
}
