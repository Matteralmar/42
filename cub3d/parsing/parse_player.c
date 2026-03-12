/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 23:25:19 by anezka            #+#    #+#             */
/*   Updated: 2026/03/03 20:48:56 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_player(t_map **map)
{
	int		count;
	int		k;
	int		i;
	char	c;

	i = 0;
	count = 0;
	while ((*map)->map[i] != NULL)
	{
		k = 0;
		while ((*map)->map[i][k] != '\0')
		{
			c = (*map)->map[i][k];
			if (c != '0' && c != '1' && c != ' ' && c != 'W'
				&& c != 'S' && c != 'N' && c != 'E' )
				return (1);
			if (c == 'W' || c == 'S' || c == 'N' || c == 'E')
				count++;
			k++;
		}
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}
