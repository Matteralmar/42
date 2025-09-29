/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newtons_julienne.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:25:24 by gvasylie          #+#    #+#             */
/*   Updated: 2025/09/29 17:15:33 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	calc_imag(double x2, double y2, double x, double y)
{
	double	x3;
	double	y3;
	double	n_real;
	double	n_imag;
	double	denom;

	x3 = x * x2 - y * y2;
	y3 = x * y2 + y * x2;
	n_real = x3 - 1;
	n_imag = y3;
	denom = 9 * x2 * x2 + 9 * y2 * y2;
	return ((n_imag * 3 * x2 - n_real * 3 * y2) / denom);
}

double	calc_real(double x2, double y2, double x, double y)
{
	double	x3;
	double	y3;
	double	n_real;
	double	n_imag;
	double	denom;

	x3 = x * x2 - y * y2;
	y3 = x * y2 + y * x2;
	n_real = x3 - 1;
	n_imag = y3;
	denom = 9 * x2 * x2 + 9 * y2 * y2;
	return ((n_real * 3 * x2 + n_imag * 3 * y2) / denom);
}

int	newton_calc(t_fract *fractol, double x, double y)
{
	int		iter;
	double	tol;
	double	x2;
	double	y2;

	tol = 1e-6;
	iter = 0;
	while (iter < fractol->iter)
	{
		x2 = x * x - y * y;
		y2 = 2 * x * y;
		y -= calc_imag(x2, y2, x, y);
		x -= calc_real(x2, y2, x, y);
		if (((x - 1) * (x - 1)) + y * y < tol * tol)
			return (RED * iter);
		if ((x + 0.5) * (x + 0.5) + (y - sqrt(3) / 2)
			* (y - sqrt(3) / 2) < tol * tol)
			return (GREEN * iter);
		if ((x + 0.5) * (x + 0.5) + (y + sqrt(3) / 2)
			* (y + sqrt(3) / 2) < tol * tol)
			return (BLUE * iter);
		iter++;
	}
	return (BLACK);
}

void	newton_julia_set(t_fract *fractol)
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
			fractol->z_y = fractol->y + (y - 600 / 2) / fractol->scale;
			fractol->z_x = fractol->x + (x - 600 / 2) / fractol->scale;
			if (fractol->type == 2)
				clr = color_calc(fractol, fractol->z_x, fractol->z_y);
			else
				clr = newton_calc(fractol, fractol->z_x, fractol->z_y);
			((int *)fractol->addr)[y * 600 + x] = clr;
			x++;
		}
		y++;
	}
}
