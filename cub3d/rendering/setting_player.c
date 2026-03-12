/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 14:33:43 by gvasylie          #+#    #+#             */
/*   Updated: 2026/03/05 14:33:44 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	setting_direction_cnt(t_map **map)
{
	if ((*map)->player->direction == 'N')
	{
		(*map)->player->dir_x = 0;
		(*map)->player->dir_y = -1;
	}
	if ((*map)->player->direction == 'S')
	{
		(*map)->player->dir_x = 0;
		(*map)->player->dir_y = 1;
	}
	if ((*map)->player->direction == 'E')
	{
		(*map)->player->dir_x = 1;
		(*map)->player->dir_y = 0;
	}
	if ((*map)->player->direction == 'W')
	{
		(*map)->player->dir_x = -1;
		(*map)->player->dir_y = 0;
	}
	return (0);
}

int	setting_direction(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while ((*map)->map[i] != NULL)
		i++;
	i = 0;
	while ((*map)->map[i] != NULL)
	{
		j = 0;
		while ((*map)->map[i][j] != '\0')
		{
			if ((*map)->map[i][j] != '0' && (*map)->map[i][j] != '1'
				&& (*map)->map[i][j] != ' ' && (*map)->map[i][j] != '\n')
				(*map)->player->direction = (*map)->map[i][j];
			j++;
		}
		i++;
	}
	setting_direction_cnt(map);
	return (0);
}

int	setting_position(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	while ((*map)->map[i] != NULL)
	{
		j = 0;
		while ((*map)->map[i][j] != '\0')
		{
			if ((*map)->map[i][j] != '0' && (*map)->map[i][j] != '1'
				&& (*map)->map[i][j] != ' ' && (*map)->map[i][j] != '\n')
			{
				(*map)->player->pos_x = j + 0.5;
				(*map)->player->pos_y = i + 0.5;
				(*map)->map[i][j] = '0';
			}
			j++;
		}
		if (j > (*map)->map_info->map_width)
			(*map)->map_info->map_width = j;
		i++;
	}
	(*map)->map_info->map_hight = i;
	return (0);
}

int	setting_plane(t_map **map)
{
	if ((*map)->player->direction == 'N')
	{
		(*map)->player->plane_x = 0.66;
		(*map)->player->plane_y = 0;
	}
	if ((*map)->player->direction == 'S')
	{
		(*map)->player->plane_x = -0.66;
		(*map)->player->plane_y = 0;
	}
	if ((*map)->player->direction == 'E')
	{
		(*map)->player->plane_x = 0;
		(*map)->player->plane_y = 0.66;
	}
	if ((*map)->player->direction == 'W')
	{
		(*map)->player->plane_x = 0;
		(*map)->player->plane_y = -0.66;
	}
	return (0);
}

int	setting_player(t_map **map)
{
	(*map)->map_info->map_width = 0;
	(*map)->map_info->map_hight = 0;
	setting_direction(map);
	setting_plane(map);
	setting_position(map);
	return (0);
}
