#include "minishell.h"

/*** @brief Initialize matches array*/
char	**init_matches_array(int *capacity)
{
	char	**matches;

	*capacity = 32;
	matches = malloc(sizeof(char *) * (*capacity));
	return (matches);
}

/*** @brief Free matches array*/
void	free_matches(char **matches, int count)
{
	int	i;

	i = 0;
	while (i < count)
		free(matches[i++]);
	free(matches);
}
