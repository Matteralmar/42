#include "minishell.h"

/*** @brief Get expanded text for word part*/
static char	*get_expanded_text(t_word_part *curr, t_info *info)
{
	char	*temp;
	char	*expanded;
	char	*wildcard_result;

	if (curr->text[0] == '$')
	{
		expanded = expand_variable(curr->text, info);
		if (expanded && ft_strchr(expanded, '*'))
		{
			temp = ft_strtrim(expanded, " \t\n\r");
			wildcard_result = expand_wildcard(temp);
			free(temp);
			free(expanded);
			return (wildcard_result);
		}
		return (expanded);
	}
	else if (ft_strchr(curr->text, '*'))
	{
		temp = ft_strtrim(curr->text, " \t\n\r");
		expanded = expand_wildcard(temp);
		free(temp);
		return (expanded);
	}
	return (ft_strdup(curr->text));
}

/*** @brief Process single word part and append to result*/
static char	*process_single_part(char *result, t_word_part *curr, t_info *info)
{
	char	*expanded;
	char	*temp;

	if (curr->q_type == DOUBLE_QUOTE && ft_strchr(curr->text, '$'))
		expanded = expand_variables_in_text(curr->text, info);
	else if (curr->q_type == NO_QUOTE
		&& (curr->expand || ft_strchr(curr->text, '*')))
		expanded = get_expanded_text(curr, info);
	else
		expanded = ft_strdup(curr->text);
	if (!expanded)
		return (free(result), NULL);
	temp = ft_strjoin(result, expanded);
	free(result);
	free(expanded);
	return (temp);
}

/*** @brief Process word parts expansion loop*/
static char	*process_parts_loop(t_word_part *parts, t_info *info)
{
	char		*result;
	t_word_part	*curr;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	curr = parts;
	while (curr)
	{
		if (curr->text && *curr->text)
		{
			result = process_single_part(result, curr, info);
			if (!result)
				return (NULL);
		}
		curr = curr->next;
	}
	return (result);
}

/*** @brief Expand and join word parts with variable expansion*/
char	*expand_and_join_parts(t_word_part *parts, t_info *info)
{
	char		*result;
	size_t		len;

	result = process_parts_loop(parts, info);
	if (!result)
		return (NULL);
	len = ft_strlen(result);
	if (len > 0 && result[len - 1] == ' ')
		result[len - 1] = '\0';
	return (result);
}
