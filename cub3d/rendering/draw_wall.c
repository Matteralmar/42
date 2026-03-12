/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:33:28 by gvasylie          #+#    #+#             */
/*   Updated: 2026/03/05 14:33:29 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_texture_pixel(t_image *texture, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= WINDOW_W || y < 0 || y >= WINDOW_H)
		return (0);
	dst = texture->addr + (y * texture->line_length + x
			* (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	calc_tex_pos(t_map *map, t_image *texture, t_wall *wall)
{
	wall->line_height = (int)(WINDOW_H / map->calc.wall_dist);
	wall->draw_start = -wall->line_height / 2 + WINDOW_H / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + WINDOW_H / 2;
	if (wall->draw_end >= WINDOW_H)
		wall->draw_end = WINDOW_H - 1;
	wall->tex_x = (int)(map->calc.wall_x * (double)texture->width);
	if (wall->tex_x >= texture->width)
		wall->tex_x = texture->width - 1;
	if ((map->calc.side == 0 && map->calc.step_x < 0)
		|| (map->calc.side == 1 && map->calc.step_y > 0))
		wall->tex_x = texture->width - wall->tex_x - 1;
	wall->step = 1.0 * texture->height / wall->line_height;
	wall->tex_pos = (wall->draw_start - WINDOW_H / 2 + wall->line_height / 2)
		* wall->step;
}

void	draw_wall(t_map *map, int x)
{
	t_wall	wall;
	t_image	*texture;
	int		y;
	int		color;

	texture = &map->texture[map->calc.text_num];
	calc_tex_pos(map, texture, &wall);
	y = wall.draw_start;
	while (y < wall.draw_end)
	{
		wall.tex_y = (int)wall.tex_pos;
		if (wall.tex_y >= texture->height)
			wall.tex_y = texture->height - 1;
		wall.tex_pos += wall.step;
		color = get_texture_pixel(texture, wall.tex_x, wall.tex_y);
		if (map->calc.side == 1)
			color = (color >> 1) & 8355711;
		color_pixel(map, x, y, color);
		y++;
	}
}
