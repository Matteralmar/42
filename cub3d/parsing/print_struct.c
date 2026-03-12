/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 16:03:09 by anezka            #+#    #+#             */
/*   Updated: 2026/03/03 21:06:57 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_struct(t_map **map)
{
	int	i;

	printf("NO texture: %s\n", (*map)->no_texture);
	printf("SO texture: %s\n", (*map)->so_texture);
	printf("EA texture: %s\n", (*map)->ea_texture);
	printf("WE texture: %s\n", (*map)->we_texture);
	printf("F colour: %d, %d, %d\n", (*map)->f_colour->red,
		(*map)->f_colour->blue, (*map)->f_colour->green);
	printf("C colour: %d, %d, %d\n", (*map)->c_colour->red,
		(*map)->c_colour->blue, (*map)->c_colour->green);
	i = 0;
	while ((*map)->map[i] != NULL)
	{
		printf("%s\n", (*map)->map[i]);
		i++;
	}
}
