/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:33:39 by gvasylie          #+#    #+#             */
/*   Updated: 2026/03/05 14:33:40 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	close_window(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	free_map(&map);
	exit(0);
}

int	game_loop(void *param)
{
	t_map	*map;

	map = (t_map *)param;
	process_movement(map);
	render(map);
	return (0);
}

int	key_press(int keycode, t_map *map)
{
	if (keycode == ESC_KEY)
		return (close_window(map), 1);
	if (keycode == 'w')
		map->key.w = 1;
	if (keycode == 's')
		map->key.s = 1;
	if (keycode == 'a')
		map->key.a = 1;
	if (keycode == 'd')
		map->key.d = 1;
	if (keycode == RIGHT_KEY)
		map->key.right = 1;
	if (keycode == LEFT_KEY)
		map->key.left = 1;
	return (0);
}

int	key_release(int keycode, t_map *map)
{
	if (keycode == 'w')
		map->key.w = 0;
	if (keycode == 's')
		map->key.s = 0;
	if (keycode == 'a')
		map->key.a = 0;
	if (keycode == 'd')
		map->key.d = 0;
	if (keycode == RIGHT_KEY)
		map->key.right = 0;
	if (keycode == LEFT_KEY)
		map->key.left = 0;
	return (0);
}

void	run_mlx(t_map *map)
{
	mlx_hook(map->win, 17, 0, close_window, map);
	mlx_hook(map->win, 2, 1L << 0, key_press, map);
	mlx_hook(map->win, 3, 1L << 1, key_release, map);
	mlx_loop_hook(map->mlx, game_loop, map);
	mlx_loop(map->mlx);
}
