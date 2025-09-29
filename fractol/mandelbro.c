/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbro.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:03:28 by gvasylie          #+#    #+#             */
/*   Updated: 2025/09/29 17:12:12 by gvasylie         ###   ########.fr       */
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
	while (y < 600)
	{
		x = 0;
		while (x < 600)
		{
			fractol->c_i = fractol->y + (y - 600 / 2) / fractol->scale;
			fractol->c_re = fractol->x + (x - 600 / 2) / fractol->scale;
			clr = color_calc(fractol, 0, 0);
			((int *)fractol->addr)[y * 600 + x] = clr;
			x++;
		}
		y++;
	}
}
