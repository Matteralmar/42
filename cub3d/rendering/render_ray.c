/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:34:05 by gvasylie          #+#    #+#             */
/*   Updated: 2026/03/05 14:37:30 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	color_pixel(t_map *map, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_W || y < 0 || y >= WINDOW_H)
		return ;
	dst = map->addr + (y * map->line_len + x * (map->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ceiling_floor(t_map *map)
{
	int	y;
	int	x;
	int	color_f;
	int	color_c;

	color_f = ((map->f_colour->red << 16)
			| (map->f_colour->green << 8) | map->f_colour->blue);
	color_c = ((map->c_colour->red << 16)
			| (map->c_colour->green << 8) | map->c_colour->blue);
	y = 0;
	while (y < WINDOW_H)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			if (y > WINDOW_H / 2)
				color_pixel(map, x, y, color_f);
			else
				color_pixel(map, x, y, color_c);
			x++;
		}
		y++;
	}
}

void	init_dda_vals(t_map *map, int x)
{
	double	camera_x;

	camera_x = (double)2 * x / WINDOW_W - 1;
	map->calc.ray_dir_x = map->player->dir_x
		+ map->player->plane_x * camera_x;
	map->calc.ray_dir_y = map->player->dir_y
		+ map->player->plane_y * camera_x;
	map->calc.map_x = (int)map->player->pos_x;
	map->calc.map_y = (int)map->player->pos_y;
	if (map->calc.ray_dir_x == 0)
		map->calc.delta_dist_x = 1e30;
	else
		map->calc.delta_dist_x = fabs(1 / map->calc.ray_dir_x);
	if (map->calc.ray_dir_y == 0)
		map->calc.delta_dist_y = 1e30;
	else
		map->calc.delta_dist_y = fabs(1 / map->calc.ray_dir_y);
}

void	what_texture(t_map *map)
{
	if (map->calc.side == 0)
	{
		if (map->calc.step_x > 0)
			map->calc.text_num = TEX_EA;
		else
			map->calc.text_num = TEX_WE;
	}
	else
	{
		if (map->calc.step_y > 0)
			map->calc.text_num = TEX_SO;
		else
			map->calc.text_num = TEX_NO;
	}
}

void	render(t_map *map)
{
	int		x;

	ceiling_floor(map);
	x = 0;
	while (x < WINDOW_W)
	{
		init_dda_vals(map, x);
		side_dist_init(map);
		perform_dda(map);
		wall_dist(map);
		what_texture(map);
		draw_wall(map, x);
		x++;
	}
	mlx_put_image_to_window(map->mlx, map->win, map->img, 0, 0);
}
