/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:33:23 by gvasylie          #+#    #+#             */
/*   Updated: 2026/03/05 14:33:24 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	side_dist_init(t_map *map)
{
	if (map->calc.ray_dir_x < 0)
	{
		map->calc.step_x = -1;
		map->calc.side_dist_x = (map->player->pos_x - map->calc.map_x)
			* map->calc.delta_dist_x;
	}
	else
	{
		map->calc.step_x = 1;
		map->calc.side_dist_x = (map->calc.map_x + 1.0 - map->player->pos_x)
			* map->calc.delta_dist_x;
	}
	if (map->calc.ray_dir_y < 0)
	{
		map->calc.step_y = -1;
		map->calc.side_dist_y = (map->player->pos_y - map->calc.map_y)
			* map->calc.delta_dist_y;
	}
	else
	{
		map->calc.step_y = 1;
		map->calc.side_dist_y = (map->calc.map_y + 1.0 - map->player->pos_y)
			* map->calc.delta_dist_y;
	}
}

void	perform_dda(t_map *map)
{
	int	max_steps;
	int	wall_hit;

	wall_hit = 0;
	max_steps = map->map_info->map_width + map->map_info->map_hight;
	while (wall_hit == 0 && --max_steps)
	{
		if (map->calc.side_dist_x < map->calc.side_dist_y)
		{
			map->calc.side_dist_x += map->calc.delta_dist_x;
			map->calc.map_x += map->calc.step_x;
			map->calc.side = 0;
		}
		else
		{
			map->calc.side_dist_y += map->calc.delta_dist_y;
			map->calc.map_y += map->calc.step_y;
			map->calc.side = 1;
		}
		if (map->map[map->calc.map_y][map->calc.map_x] == '1')
			wall_hit = 1;
	}
}

void	wall_dist(t_map *map)
{
	if (map->calc.side == 1)
		map->calc.wall_dist = map->calc.side_dist_y - map->calc.delta_dist_y;
	else
		map->calc.wall_dist = map->calc.side_dist_x - map->calc.delta_dist_x;
	if (map->calc.side == 1)
		map->calc.wall_x = map->player->pos_x + map->calc.wall_dist
			* map->calc.ray_dir_x;
	else
		map->calc.wall_x = map->player->pos_y + map->calc.wall_dist
			* map->calc.ray_dir_y;
	map->calc.wall_x -= floor(map->calc.wall_x);
}
