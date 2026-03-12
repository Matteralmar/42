/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_borders_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:29:01 by anezka            #+#    #+#             */
/*   Updated: 2026/03/03 21:34:51 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	borders_next_space_loop(t_map **map, int count, int *space_pos, int i)
{
	int	k;

	k = 0;
	while (count > 0)
	{
		if ((*map)->map[i][space_pos[k] - 1] != '1'
			&& (*map)->map[i][space_pos[k] - 1] != ' ')
			free_borders_loop(space_pos, map);
		if ((*map)->map[i][space_pos[k] + 1] != '1'
			&& (*map)->map[i][space_pos[k] + 1] != ' ')
			free_borders_loop(space_pos, map);
		count--;
		k++;
	}
	return (0);
}

int	count_spaces(t_map **map, int i)
{
	int	count;
	int	j;

	count = 0;
	j = 0;
	while ((*map)->map[i][j] == ' ')
		j++;
	while ((*map)->map[i][j] != '\0')
	{
		if ((*map)->map[i][j] == ' ')
			count++;
		j++;
	}
	while (i > 0 && ((*map)->map[i][j] != '1' && (*map)->map[i][j] != '0'))
	{
		if ((*map)->map[i][j] == ' ')
			count--;
		j--;
	}
	(*map)->map_info->space_count = count;
	return (count);
}

int	add_position(char *line, char find, int last)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] == find && i > last)
			return (i);
		i++;
	}
	return (-1);
}

int	*space_positions(t_map **map, int i)
{
	int	count;
	int	last;
	int	j;
	int	*positions;

	count = count_spaces(map, i);
	if (count == 0)
		return (NULL);
	positions = malloc(sizeof(int) * count);
	if (positions == NULL)
	{
		perror("Error\n");
		free_map(map);
		exit (1);
	}
	last = 0;
	j = 0;
	while (count > 0)
	{
		positions[j] = add_position((*map)->map[i], ' ', last);
		last = positions[j];
		j++;
		count--;
	}
	return (positions);
}

int	check_first_border(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
