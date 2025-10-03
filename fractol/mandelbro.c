/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:03:28 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/03 13:50:55 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	color_calc(t_fract *fractol, double x, double y)
{
	double	tmp;
	int		clr;
	int		iter;

	iter = 0;
	while ((x * x + y * y <= 4) && (iter < fractol->iter))
	{
		tmp = x * x - y * y + fractol->c_re;
		y = 2.0 * x * y + fractol->c_i;
		x = tmp;
		iter++;
	}
	if (iter == fractol->iter)
		return (BLACK);
	clr = fractol->color * iter;
	return (clr);
}

void	mandelbrot_set(t_fract *fractol)
{
	int	clr;
	int	x;
	int	y;

	y = 0;
	mlx_clear_window(fractol->mlx, fractol->win);
	while (y < WID_HEI)
	{
		x = 0;
		while (x < WID_HEI)
		{
			fractol->c_i = fractol->y + (y - WID_HEI / 2) / fractol->scale;
			fractol->c_re = fractol->x + (x - WID_HEI / 2) / fractol->scale;
			clr = color_calc(fractol, 0, 0);
			((int *)fractol->addr)[y * WID_HEI + x] = clr;
			x++;
		}
		y++;
	}
}
