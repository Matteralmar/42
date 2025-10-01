/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:03:23 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/01 18:06:16 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	destroy(t_fract *fractal)
{
	if (fractal->img)
		mlx_destroy_image(fractal->mlx, fractal->img);
	if (fractal->win)
		mlx_destroy_window(fractal->mlx, fractal->win);
	if (fractal->mlx)
	{
		mlx_loop_end(fractal->mlx);
		mlx_destroy_display(fractal->mlx);
		free(fractal->mlx);
	}
	exit(0);
}

static int	mouse_hook(int button, int x, int y, void *param)
{
	t_fract	*fractal;
	double	old_re;
	double	old_im;
	double	new_re;
	double	new_im;

	fractal = (t_fract *)param;
	old_re = fractal->x + (x - WID_HEI / 2) / fractal->scale;
	old_im = fractal->y + (y - WID_HEI / 2) / fractal->scale;
	if (button == 4)
		fractal->zoom *= 0.9;
	else if (button == 5)
		fractal->zoom *= 1.1;
	fractal->scale = WID_HEI / (4.0 * fractal->zoom);
	new_re = fractal->x + (x - WID_HEI / 2) / fractal->scale;
	new_im = fractal->y + (y - WID_HEI / 2) / fractal->scale;
	fractal->x += old_re - new_re;
	fractal->y += old_im - new_im;
	draw(fractal);
	return (0);
}

static int	action(int action, t_fract *fractal)
{
	if (action == UP)
		fractal->y -= 0.1 * fractal->zoom;
	if (action == DOWN)
		fractal->y += 0.1 * fractal->zoom;
	if (action == LEFT)
		fractal->x -= 0.1 * fractal->zoom;
	if (action == RIGHT)
		fractal->x += 0.1 * fractal->zoom;
	if (action == '1')
		fractal->color += 99;
	if (action == '2')
		fractal->color -= 99;
	if (action == 65307)
		destroy(fractal);
	if (action == 'q')
		fractal->c_i += 0.01;
	if (action == 'w')
		fractal->c_i -= 0.01;
	if (action == 'e')
		fractal->c_re += 0.01;
	if (action == 'r')
		fractal->c_re -= 0.01;
	if (action == 'i')
		fractal->iter += 40;
	return (draw(fractal), 0);
}

void	hooks(t_fract *fractal)
{
	mlx_hook(fractal->win, 4, 1L << 2, mouse_hook, fractal);
	mlx_key_hook(fractal->win, action, fractal);
	mlx_hook(fractal->win, 17, 0, destroy, fractal);
}
