/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julien.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:25:24 by gvasylie          #+#    #+#             */
/*   Updated: 2025/09/26 16:23:12 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_set(t_fract *fractol)
{
	int	clr;
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(fractol->mlx, fractol->win);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			fractol->z_y = fractol->y + (y - HEIGHT / 2) / fractol->scale;
			fractol->z_x = fractol->x + (x - WIDTH / 2) / fractol->scale;
			clr = color_calc(fractol, fractol->z_x, fractol->z_y);
			((int *)fractol->addr)[y * WIDTH + x] = clr;
			x++;
		}
		y++;
	}
}
