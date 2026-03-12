/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:49:57 by anezkahavra       #+#    #+#             */
/*   Updated: 2026/03/03 21:30:08 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_all(t_map **map, char *line)
{
	(void)line;
	if ((*map)->no_texture == NULL || (*map)->so_texture == NULL
		|| (*map)->we_texture == NULL || (*map)->ea_texture == NULL)
	{
		ft_putstr_fd("Error\nTextures\n", STDERR_FILENO);
		free(line);
		free_map(map);
		exit (1);
	}
	if ((*map)->c_colour->red < 0 || (*map)->f_colour->red < 0)
	{
		ft_putstr_fd("Error\nColours\n", STDERR_FILENO);
		free(line);
		free_map(map);
		exit (1);
	}
	if (check_player(map) == 1)
	{
		ft_putstr_fd("Map invalid\n", STDERR_FILENO);
		free(line);
		free_map(map);
		exit (1);
	}
	return (0);
}

int	correct_format(char *argv)
{
	if (ft_strlen(argv) < 5)
	{
		ft_putstr_fd("Error\nOne *.cub file needed\n", STDERR_FILENO);
		exit (1);
	}
	if (ft_strncmp(argv + ft_strlen(argv) - 4, ".cub", 5) != 0)
	{
		ft_putstr_fd("Error\nOne *.cub file needed\n", STDERR_FILENO);
		exit (1);
	}
	return (0);
}

int	correct_textures(t_map **map, char *line)
{
	int	fd;
	int	fd2;
	int	fd3;
	int	fd4;

	fd = open((*map)->no_texture, O_RDONLY);
	fd2 = open((*map)->so_texture, O_RDONLY);
	fd3 = open((*map)->ea_texture, O_RDONLY);
	fd4 = open((*map)->we_texture, O_RDONLY);
	if (fd == -1 || fd2 == -1 || fd3 == -1 || fd4 == -1)
	{
		free_map(map);
		free(line);
		ft_putstr_fd("Error\nTextures\n", STDERR_FILENO);
		exit (1);
	}
	return (0);
}

int	opening_cubfile(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		perror(".cub file");
		exit (1);
	}
	return (fd);
}

//	print_struct(map);
int	parse_crossroad(char *argv, t_map **map)
{
	int		fd;
	char	*line;

	correct_format(argv);
	fd = opening_cubfile(argv);
	set_map_struct(map);
	line = get_next_line(fd);
	while (line)
	{
		if (find_texture_colours(line) == 0)
			parsing_elements_textures(line, map);
		else
			prepare_parse_map(line, map);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	check_all_borders(map);
	check_all(map, line);
	correct_textures(map, line);
	free(line);
	return (0);
}
