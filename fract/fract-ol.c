#include "fractol.h"

void	init_fractal(t_fract *fractal)
{
	fractal->iter = 200;
	fractal->zoom = 1;
	fractal->x = 0;
	fractal->y = 0;
	fractal->z_x = 0;
	fractal->z_y = 270;
	fractal->color = 0xccf1ff;
}

void	error_msg(int i)
{
	if (i == 1)
        ft_putendl_fd("Error: MLX initialization failed", 2);
    else if (i == 2)
        ft_putendl_fd("Usage: ./fractol <Mandelbrot|Julia|BurningShip>", 2);
}

void draw(t_fract *fractal)
{
    if (fractal->type == 1)
        mandelbrot_set(fractal); //TODO
    else if (fractal->type == 2)
        julia_set(fractal); //TODO
    else if (fractal->type == 3)
        burningship_set(fractal); //TODO
    mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	
}

int what_set(t_fract *fractal, char **av)
{
	init_fractal(fractal);
    if (!ft_strncmp(av[1], "Mandelbrot", 11))
        fractal->type = 1;
    else if (!ft_strncmp(av[1], "Julia", 6))
        fractal->type = 2;
    else if (!ft_strncmp(av[1], "BurningShip", 12))
        fractal->type = 3;
    else
	{
		error_msg(2);
		destroy(fractal);
	}
    return 0;
}


int main(int ac, char **av)
{
	t_fract	fractal;

	if(ac == 2)
	{
		fractal.mlx = mlx_init();
		if (!fractal.mlx)
            return (error_msg(1), 1);
		fractal.win = mlx_new_window(fractal.mlx, WIDTH, HEIGHT, "fract-ol");
		if (!fractal.win)
            return (error_msg(1), 1);
		fractal.img = mlx_new_image(fractal.mlx, WIDTH, HEIGHT);
		if (!fractal.img)
            return (error_msg(1), 1);
		fractal.addr = mlx_get_data_addr(fractal.img,
		&fractal.bits_per_pixel, &fractal.line_len, &fractal.endian);
		if (!fractal.addr)
            return (error_msg(1), 1);
		what_set(&fractal, av);
		draw(&fractal);
		hooks(&fractal);	
		mlx_loop(fractal.mlx);
	}
	else
		return (error_msg(2), 1);
	return 0;
}

