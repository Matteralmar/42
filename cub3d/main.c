/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 21:07:45 by ahavrank          #+#    #+#             */
/*   Updated: 2026/03/03 21:25:34 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	*map;

	map = NULL;
	if (argc != 2)
	{
		ft_putstr_fd("Error\nOne *.cub file needed\n", STDERR_FILENO);
		return (1);
	}
	else
		parse_crossroad(argv[1], &map);
	if (setup_game(&map))
		return (free_map(&map), 1);
	run_mlx(map);
	return (0);
}
