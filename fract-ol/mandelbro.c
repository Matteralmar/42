# include "fractol.h"

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
	if(iter == fractol->iter)
		return 0x000000;
	clr = fractol->color * iter;
	return clr;
}

void	mandelbrot_set(t_fract *fractol)
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
			fractol->c_i = fractol->y + (y - HEIGHT / 2) / fractol->scale;
			fractol->c_re = fractol->x + (x - WIDTH / 2) / fractol->scale;
			clr = color_calc(fractol, 0, 0);
			char *dst = fractol->addr + (y * fractol->line_len + x * (fractol->bits_per_pixel / 8));
			*(int *)dst = clr;

			x++;
		}
		y++;
	}
}
