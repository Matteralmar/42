#include "minishell.h"

/*** @brief Add text segment to result*/
char	*join_segment(char *result, char *segment)
{
	char	*new_result;

	new_result = ft_strjoin(result, segment);
	free(segment);
	free(result);
	return (new_result);
}

/*** @brief Process literal text before $*/
char	*add_literal(char *result, char *text, size_t *i)
{
	size_t	start;

	start = *i;
	while (text[*i] && text[*i] != '$')
		(*i)++;
	if (*i > start)
		return (join_segment(result, ft_substr(text, start, *i - start)));
	return (result);
}

/*** @brief Expand variables in text (handles multiple $ in string)*/
char	*expand_variables_in_text(char *text, t_info *info)
{
	char	*result;
	size_t	i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (text[i])
	{
		result = add_literal(result, text, &i);
		if (!result || !text[i])
			return (result);
		i++;
		result = join_segment(result, get_var_value(text, &i, info));
		if (!result)
			return (NULL);
	}
	return (result);
}
