/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:46:26 by anezka            #+#    #+#             */
/*   Updated: 2026/03/03 21:06:57 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	parsing_elements_colours_cnt(char *line, t_map **map)
{
	if (ft_strncmp(line, "C ", 2) == 0)
	{
		(*map)->c_colour->red = colour_values(line, 1);
		if ((*map)->c_colour->red == -1)
			free_colours(line, map);
		(*map)->c_colour->green = colour_values(line, 2);
		if ((*map)->c_colour->green == -1)
			free_colours(line, map);
		(*map)->c_colour->blue = colour_values(line, 3);
		if ((*map)->c_colour->blue == -1)
			free_colours(line, map);
	}
	return (0);
}

int	parsing_elements_colours(char *line, t_map **map)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		(*map)->f_colour->red = colour_values(line, 1);
		if ((*map)->f_colour->red == -1)
			free_colours(line, map);
		(*map)->f_colour->green = colour_values(line, 2);
		if ((*map)->f_colour->green == -1)
			free_colours(line, map);
		(*map)->f_colour->blue = colour_values(line, 3);
		if ((*map)->f_colour->blue == -1)
			free_colours(line, map);
	}
	return (0);
}
