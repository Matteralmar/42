/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:33:31 by gvasylie          #+#    #+#             */
/*   Updated: 2026/03/05 14:46:37 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_moves(t_map *map, double move_x, double move_y)
{
	double	new_x;
	double	new_y;
	double	margin;

	margin = 0.1;
	new_x = map->player->pos_x + move_x;
	new_y = map->player->pos_y + move_y;
	if (move_x > 0 && (int)(new_x + margin) < map->map_info->map_width &&
		map->map[(int)map->player->pos_y][(int)(new_x + margin)] != '1')
		map->player->pos_x = new_x;
	else if (move_x < 0 && (int)(new_x - margin) >= 0 &&
		map->map[(int)map->player->pos_y][(int)(new_x - margin)] != '1')
		map->player->pos_x = new_x;
	if (move_y > 0 && (int)(new_y + margin) < map->map_info->map_hight &&
		map->map[(int)(new_y + margin)][(int)map->player->pos_x] != '1')
		map->player->pos_y = new_y;
	else if (move_y < 0 && (int)(new_y - margin) >= 0 &&
		map->map[(int)(new_y - margin)][(int)map->player->pos_x] != '1')
		map->player->pos_y = new_y;
}

void	player_rotates(t_map *map, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = map->player->dir_x;
	map->player->dir_x = map->player->dir_x * cos(-angle)
		- map->player->dir_y * sin(-angle);
	map->player->dir_y = old_dir_x * sin(-angle)
		+ map->player->dir_y * cos(-angle);
	old_plane_x = map->player->plane_x;
	map->player->plane_x = map->player->plane_x * cos(-angle)
		- map->player->plane_y * sin(-angle);
	map->player->plane_y = old_plane_x * sin(-angle)
		+ map->player->plane_y * cos(-angle);
}

int	process_movement(t_map *map)
{
	if (map->key.w)
		player_moves(map, MV_SPEED * map->player->dir_x,
			MV_SPEED * map->player->dir_y);
	if (map->key.d)
		player_moves(map, MV_SPEED * map->player->plane_x,
			MV_SPEED * map->player->plane_y);
	if (map->key.s)
		player_moves(map, MV_SPEED * -map->player->dir_x,
			MV_SPEED * -map->player->dir_y);
	if (map->key.a)
		player_moves(map, MV_SPEED * -map->player->plane_x,
			MV_SPEED * -map->player->plane_y);
	if (map->key.left)
		player_rotates(map, RT_SPEED);
	if (map->key.right)
		player_rotates(map, -RT_SPEED);
	return (0);
}
