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

int action(int key, t_fract *fractal)
{
    if (key == 65363) // Right
        fractal->x += 0.1 * fractal->zoom;
    if (key == 65361) // Left
        fractal->x -= 0.1 * fractal->zoom;
    if (key == 65364) // Down
        fractal->y += 0.1 * fractal->zoom;
    if (key == 65362) // Up
        fractal->y -= 0.1 * fractal->zoom;
    if (key == 65307) // ESC
        destroy(fractal);
    if (key == 65451) // color +
        fractal->color += 100;
    if (key == 65453) // color -
        fractal->color -= 100;
    if (key == 'q')
        fractal->c_i += 0.01;
    if (key == 'w')
        fractal->c_i -= 0.01;
    if (key == 'e')
        fractal->c_re += 0.01;
    if (key == 'r')
        fractal->c_re -= 0.01;
    draw(fractal);
    return (0);
}

int mouse_hook(int button, int x, int y, void *param)
{
    t_fract *fractal;

    (void)x;
    (void)y;
    fractal = (t_fract *)param;
    if (button == 5)        // Scroll up
        fractal->zoom *= 1.1;
    else if (button == 4)   // Scroll down
        fractal->zoom *= 0.9;
    draw(fractal);
    return (0);
}

void hooks(t_fract *fractal)
{
    mlx_mouse_hook(fractal->win, mouse_hook, fractal);
    mlx_key_hook(fractal->win, action, fractal);
    mlx_hook(fractal->win, 17, 0, destroy, fractal); // Close window (X)
}
