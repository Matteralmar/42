#include "minishell.h"

/*** @brief Free allocated array on error*/
static void	free_args_array(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(arr[i++]);
	free(arr);
}

/*** @brief Count arguments in linked list*/
static int	count_args(t_arg *args, t_info *info)
{
	int		count;
	t_arg	*curr;
	char	*expanded;

	count = 0;
	curr = args;
	while (curr)
	{
		expanded = expand_and_join_parts(curr->word_parts, info);
		if (expanded && *expanded)
		{
			if (contains_wildcard_expansion(curr))
				count += count_words(expanded);
			else
				count++;
		}
		free(expanded);
		curr = curr->next;
	}
	return (count);
}

/*** @brief Process single argument and add to array*/
static int	process_arg(char **arr, int i, t_arg *curr, t_info *info)
{
	char	*expanded;

	expanded = expand_and_join_parts(curr->word_parts, info);
	if (!expanded)
		return (-1);
	if (!*expanded)
		return (free(expanded), i);
	if (contains_wildcard_expansion(curr))
	{
		i = add_split_words(arr, i, expanded);
		free(expanded);
	}
	else
		arr[i++] = expanded;
	return (i);
}

/*** @brief Convert t_arg linked list to char** array for execve*/
char	**args_to_array(t_arg *args, t_info *info)
{
	char	**arr;
	t_arg	*curr;
	int		i;

	arr = malloc(sizeof(char *) * (count_args(args, info) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	curr = args;
	while (curr)
	{
		i = process_arg(arr, i, curr, info);
		if (i < 0)
			return (free_args_array(arr, 0), NULL);
		curr = curr->next;
	}
	arr[i] = NULL;
	return (arr);
}
