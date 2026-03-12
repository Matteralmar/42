/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 21:35:21 by ahavrank          #+#    #+#             */
/*   Updated: 2026/03/03 21:31:02 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player(t_map **map)
{
	(*map)->player = malloc(sizeof(t_player));
	if ((*map)->player == NULL)
	{
		perror("Error\n");
		free_map(map);
		exit (1);
	}
	(*map)->player->direction = '\0';
}

void	set_start_colours(t_map **map)
{
	(*map)->f_colour->blue = -1;
	(*map)->f_colour->red = -1;
	(*map)->f_colour->green = -1;
	(*map)->c_colour->blue = -1;
	(*map)->c_colour->red = -1;
	(*map)->c_colour->green = -1;
	(*map)->map_info = NULL;
	(*map)->map_info = malloc(sizeof(t_map_info));
	if ((*map)->map_info == NULL)
	{
		perror("Error\n");
		free_map(map);
		exit (1);
	}
	(*map)->map_info->line_count = 0;
	(*map)->map_info->space_count = 0;
	(*map)->player = NULL;
	set_player(map);
}

void	set_map_struct(t_map **map)
{
	*map = malloc(sizeof(t_map));
	if (*map == NULL)
	{
		perror("Error\n");
		exit(1);
	}
	ft_memset(*map, 0, sizeof(t_map));
	(*map)->no_texture = NULL;
	(*map)->so_texture = NULL;
	(*map)->we_texture = NULL;
	(*map)->ea_texture = NULL;
	(*map)->f_colour = NULL;
	(*map)->c_colour = NULL;
	(*map)->map = NULL;
	(*map)->head_map = NULL;
	(*map)->f_colour = malloc(sizeof(t_colour));
	(*map)->c_colour = malloc(sizeof(t_colour));
	if ((*map)->f_colour == NULL || (*map)->c_colour == NULL)
	{
		perror("Error\n");
		free_map(map);
		exit (1);
	}
	set_start_colours(map);
}
