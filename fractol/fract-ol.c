/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:03:13 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/01 18:03:15 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractal(t_fract *fractal)
{
	if (fractal->type == 1 || fractal->type == 2)
		fractal->iter = 140;
	else
		fractal->iter = 100;
	fractal->zoom = 1;
	fractal->scale = WID_HEI / (fractal->zoom * 4);
	fractal->color = COLOR;
	fractal->x = 0;
	fractal->y = 0;
	fractal->z_x = 0;
	fractal->z_y = 0;
	if (fractal->type == 2)
	{
		fractal->c_re = -0.855000;
		fractal->c_i = -0.007900;
	}
}

static void	error_msg(int i)
{
	if (i == 1)
		ft_putendl_fd("Error: MLX initialization failed", 2);
	else if (i == 2)
		ft_putendl_fd("Usage: ./fractol <Mandelbrot|Julia|Newton>", 2);
}

void	draw(t_fract *fractal)
{
	if (fractal->type == 1)
		mandelbrot_set(fractal);
	else if (fractal->type == 2)
		newton_julia_set(fractal);
	else if (fractal->type == 3)
		newton_julia_set(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}

static int	what_set(t_fract *fractal, char **av)
{
	if (!ft_strncmp(av[1], "Mandelbrot", 11))
		fractal->type = 1;
	else if (!ft_strncmp(av[1], "Julia", 6))
		fractal->type = 2;
	else if (!ft_strncmp(av[1], "Newton", 12))
		fractal->type = 3;
	else
	{
		error_msg(2);
		destroy(fractal);
	}
	init_fractal(fractal);
	return (0);
}

int	main(int ac, char **av)
{
	t_fract	fractal;

	if (ac == 2)
	{
		fractal.mlx = mlx_init();
		if (!fractal.mlx)
			return (error_msg(1), 1);
		fractal.win = mlx_new_window(fractal.mlx, WID_HEI, WID_HEI, "fract-ol");
		if (!fractal.win)
			return (destroy(&fractal), error_msg(1), 1);
		fractal.img = mlx_new_image(fractal.mlx, WID_HEI, WID_HEI);
		if (!fractal.img)
			return (destroy(&fractal), error_msg(1), 1);
		fractal.addr = mlx_get_data_addr(fractal.img,
				&fractal.bits_per_pixel, &fractal.line_len, &fractal.endian);
		if (!fractal.addr)
			return (destroy(&fractal), error_msg(1), 1);
		what_set(&fractal, av);
		draw(&fractal);
		hooks(&fractal);
		mlx_loop(fractal.mlx);
	}
	else
		return (error_msg(2), 1);
	return (0);
}
