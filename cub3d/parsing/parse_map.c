/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:11 by anezka            #+#    #+#             */
/*   Updated: 2026/03/03 21:33:16 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	compare_end_borders(int end, t_map **map, int spot)
{
	int	prev_end;
	int	border_cont;

	if (spot == 0)
		return (0);
	prev_end = find_border((*map)->map[spot - 1], 1);
	if (end < prev_end)
	{
		border_cont = still_border((*map)->map[spot - 1], 1);
		if (border_cont > end)
			return (1);
	}
	else if (end > prev_end)
	{
		border_cont = still_border((*map)->map[spot], 1);
		if (border_cont > prev_end)
			return (1);
	}
	return (0);
}

int	compare_start_borders(int start, t_map **map, int spot)
{
	int	prev_start;
	int	border_cont;

	if (spot == 0)
		return (0);
	prev_start = find_border((*map)->map[spot - 1], 0);
	if (prev_start > start)
	{
		border_cont = still_border((*map)->map[spot], 0);
		if (border_cont < prev_start)
			return (1);
	}
	else if (prev_start < start)
	{
		border_cont = still_border((*map)->map[spot - 1], 0);
		if (border_cont < start)
			return (1);
	}
	return (0);
}

char	**parse_map2(char *line, t_map **map, int count)
{
	char	**temp_map;

	temp_map = malloc(sizeof(char *) * (count + 2));
	if (temp_map == NULL)
	{
		perror("Error\n");
		free_in_parsing_map(line, map, temp_map);
	}
	return (temp_map);
}

int	parse_map(char *line, t_map **map)
{
	static int	count;
	char		**temp_map;
	int			i;

	temp_map = parse_map2(line, map, count);
	i = 0;
	while ((*map)->map != NULL && (*map)->map[i] != NULL)
	{
		temp_map[i] = (*map)->map[i];
		i++;
	}
	free((*map)->map);
	(*map)->map = temp_map;
	(*map)->map[count] = ft_strdup(line);
	if ((*map)->map[count] == NULL)
	{
		ft_putstr_fd("Error\nMap is not valid\n", STDERR_FILENO);
		free_in_parsing_map(line, map, temp_map);
	}
	(*map)->map[count] = trim_map_line((*map)->map[count]);
	count++;
	(*map)->map[count] = NULL;
	(*map)->map_info->line_count++;
	return (0);
}

int	prepare_parse_map(char *line, t_map **map)
{
	static int	before_map;

	if (part_of_map(line) == 1 && gibberish_present(line) == 1)
	{
		ft_putstr_fd("Error\nMap is invalid\n", STDERR_FILENO);
		free(line);
		get_next_line(-3);
		free_map(map);
		exit (1);
	}
	if (part_of_map(line) == 0 && empty_line(line) == 0)
	{
		if (before_map == 1)
		{
			ft_putstr_fd("Error\nMap is invalid\n", STDERR_FILENO);
			free(line);
			get_next_line(-3);
			free_map(map);
			exit (1);
		}
		return (0);
	}
	parse_map(line, map);
	before_map = 1;
	return (0);
}
