/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   for_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:38:02 by anezka            #+#    #+#             */
/*   Updated: 2026/03/03 17:45:58 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_in_parsing_map(char *line, t_map **map, char **temp_map)
{
	free(line);
	free_map(map);
	get_next_line(-3);
	if (temp_map != NULL)
		free(temp_map);
	exit(1);
}

// printf("%s", msg);
void	map_invalid(t_map **map, char *msg)
{
	(void)msg;
	ft_putstr_fd("Error\nMap is invalid\n", STDERR_FILENO);
	free_map(map);
	exit (1);
}

void	free_borders_loop(int *space_pos, t_map **map)
{
	free(space_pos);
	map_invalid(map, "Error\nMap is invalid\n");
}

void	free_colours(char *line, t_map **map)
{
	free(line);
	get_next_line(-3);
	free_map(map);
	exit (1);
}
