#include "minishell.h"

/*** @brief Initialization of main struct*/
t_info	*init_info(void)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (ft_dprintf("Malloc allocation failed"), NULL);
	info->envs = NULL;
	info->tokens = NULL;
	info->ast = NULL;
	return (info);
}
