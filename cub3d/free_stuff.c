/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 21:07:29 by ahavrank          #+#    #+#             */
/*   Updated: 2026/03/03 21:07:36 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_strings(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		strings[i] = NULL;
		i++;
	}
	free(strings);
	strings = NULL;
}

void	free_pt3(t_map **map)
{
	if ((*map)->map != NULL)
	{
		free((*map)->map);
		(*map)->map = NULL;
	}
	if ((*map)->map_info != NULL)
	{
		free((*map)->map_info);
		(*map)->map_info = NULL;
	}
	if ((*map)->player != NULL)
	{
		free((*map)->player);
		(*map)->player = NULL;
	}
	free((*map));
	(*map) = NULL;
}

void	free_rest(t_map **map)
{
	int	i;

	i = 0;
	if ((*map)->f_colour != NULL)
	{
		free((*map)->f_colour);
		(*map)->f_colour = NULL;
	}
	if ((*map)->c_colour != NULL)
	{
		free((*map)->c_colour);
		(*map)->c_colour = NULL;
	}
	if ((*map)->map != NULL)
	{
		i = 0;
		while ((*map)->map[i] != NULL)
		{
			free((*map)->map[i]);
			(*map)->map[i] = NULL;
			i++;
		}
	}
	free_pt3(map);
}

void	free_mlx(t_map *map)
{
	int	i;

	if (!map || !map->mlx)
		return ;
	i = 0;
	while (i < 4)
	{
		if (map->texture[i].img)
		{
			mlx_destroy_image(map->mlx, map->texture[i].img);
			map->texture[i].img = NULL;
		}
		i++;
	}
	if (map->img)
		mlx_destroy_image(map->mlx, map->img);
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	map->mlx = NULL;
}

void	free_map(t_map **map)
{
	free_mlx(*map);
	if ((*map)->no_texture != NULL)
	{
		free((*map)->no_texture);
		(*map)->no_texture = NULL;
	}
	if ((*map)->so_texture != NULL)
	{
		free((*map)->so_texture);
		(*map)->so_texture = NULL;
	}
	if ((*map)->we_texture != NULL)
	{
		free((*map)->we_texture);
		(*map)->we_texture = NULL;
	}
	if ((*map)->ea_texture != NULL)
	{
		free((*map)->ea_texture);
		(*map)->ea_texture = NULL;
	}
	free_rest(map);
}
