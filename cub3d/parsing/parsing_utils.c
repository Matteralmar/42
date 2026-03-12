/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 20:38:45 by ahavrank          #+#    #+#             */
/*   Updated: 2026/03/03 21:20:04 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_texture_colours(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (0);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (0);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (0);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (0);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (0);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (0);
	return (1);
}

int	free_borders_loop_cnt(t_map **map, int k, int *space_pos, int i)
{
	char	c_up;
	char	c_down;

	c_up = ((*map)->map[i - 1][space_pos[k]]);
	c_down = ((*map)->map[i + 1][space_pos[k]]);
	if ((c_up != '1' && c_up != ' ' && c_up != '\0')
		|| (c_down != '1' && c_down != ' ' && c_down != '\0'))
		return (1);
	return (0);
}
