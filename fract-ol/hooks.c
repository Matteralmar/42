#include "fractol.h"

int destroy(t_fract *fractal)
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

int mouse_hook(int button, int x, int y, void *param)
{
    t_fract *fractal = (t_fract *)param;

    (void)x;
    (void)y;

    if (button == 5)        // Scroll down -> zoom in
        fractal->zoom *= 1.1;
    else if (button == 4)   // Scroll up-> zoom out
        fractal->zoom *= 0.9;

    fractal->scale = (double)WIDTH / (4.0 * fractal->zoom);
    draw(fractal);
    return (0);
}


int action(int action, t_fract *fractal)
{
    if (action == 65362) // Up
        fractal->y -= 0.1 * fractal->zoom;
    if (action == 65364) // Down
        fractal->y += 0.1 * fractal->zoom;
    if (action == 65361) // Left
        fractal->x -= 0.1 * fractal->zoom;
    if (action == 65363) // Right
        fractal->x += 0.1 * fractal->zoom;
    if (action == 65451) // color +
        fractal->color += 99;
    if (action == 65453) // color -
        fractal->color -= 99;
    if (action == 65307) // ESC
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

void hooks(t_fract *fractal)
{
    mlx_hook(fractal->win, 4, 1L << 2, mouse_hook, fractal);
    mlx_key_hook(fractal->win, action, fractal);
    mlx_hook(fractal->win, 17, 0, destroy, fractal); // Close window (X)
}
