#include "minishell.h"

/*** @brief Check if arg contains wildcard expansion result (has spaces)*/
int	contains_wildcard_expansion(t_arg *arg)
{
	t_word_part	*curr;

	if (!arg || !arg->word_parts)
		return (0);
	curr = arg->word_parts;
	while (curr)
	{
		if (curr->q_type == NO_QUOTE && curr->text
			&& ft_strchr(curr->text, '*'))
			return (1);
		curr = curr->next;
	}
	return (0);
}

/*** @brief Count how many words in a space-separated string*/
int	count_words(const char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
		{
			if (!in_word)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		str++;
	}
	return (count);
}

/*** @brief Free words array helper*/
static void	free_words_array(char **words)
{
	int	i;

	i = 0;
	while (words[i])
		free(words[i++]);
	free(words);
}

/*** @brief Add split words from expanded string to array*/
int	add_split_words(char **arr, int idx, char *expanded)
{
	char	**words;
	int		i;

	words = ft_split(expanded, ' ');
	if (!words)
		return (idx);
	i = 0;
	while (words[i])
	{
		arr[idx] = ft_strdup(words[i]);
		if (!arr[idx])
		{
			while (i >= 0)
				free(words[i--]);
			free(words);
			return (-1);
		}
		idx++;
		i++;
	}
	free_words_array(words);
	return (idx);
}
