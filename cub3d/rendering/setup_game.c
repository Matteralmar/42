/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:33:47 by gvasylie          #+#    #+#             */
/*   Updated: 2026/03/05 14:33:48 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	setting_mlx(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
		return (ft_putstr_fd("MLX init failed\n", STDERR_FILENO), 1);
	map->win = mlx_new_window(map->mlx,
			WINDOW_W, WINDOW_H, "cub3D");
	if (!map->win)
		return (ft_putstr_fd("Window init failed\n", STDERR_FILENO), 1);
	map->img = mlx_new_image(map->mlx,
			WINDOW_W, WINDOW_H);
	if (!map->img)
		return (ft_putstr_fd("Image init failed\n", STDERR_FILENO), 1);
	map->addr = mlx_get_data_addr(map->img,
			&map->bpp, &map->line_len,
			&map->endian);
	if (!map->addr)
		return (ft_putstr_fd("Address init failed\n", STDERR_FILENO), 1);
	return (0);
}

static int	load_texture(t_map *map, int i, char *path)
{
	if (!path)
		return (ft_putstr_fd("Texture missing\n", 2), 1);
	map->texture[i].img = mlx_xpm_file_to_image(
			map->mlx, path,
			&map->texture[i].width,
			&map->texture[i].height);
	if (!map->texture[i].img)
		return (ft_putstr_fd("Failed to load texture\n", 2), 1);
	map->texture[i].addr = mlx_get_data_addr(
			map->texture[i].img,
			&map->texture[i].bits_per_pixel,
			&map->texture[i].line_length,
			&map->texture[i].endian);
	if (!map->texture[i].addr)
		return (ft_putstr_fd("Failed texture addr\n", 2), 1);
	return (0);
}

int	setting_textures(t_map *map)
{
	if (load_texture(map, 0, map->no_texture))
		return (1);
	if (load_texture(map, 1, map->so_texture))
		return (1);
	if (load_texture(map, 2, map->we_texture))
		return (1);
	if (load_texture(map, 3, map->ea_texture))
		return (1);
	return (0);
}

void	set_keys(t_map *map)
{
	map->key.w = 0;
	map->key.s = 0;
	map->key.a = 0;
	map->key.d = 0;
	map->key.right = 0;
	map->key.left = 0;
}

int	setup_game(t_map **map)
{
	setting_player(map);
	if (setting_mlx(*map))
		return (1);
	if (setting_textures(*map))
		return (1);
	set_keys(*map);
	return (0);
}
