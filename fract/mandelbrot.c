/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njard <njard@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:46:19 by njard             #+#    #+#             */
/*   Updated: 2025/01/27 15:42:43 by njard            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fractol.h"

// static int calculate_mandelbrot_color(t_fract *fractal)
// {
//     int iter = 0;
//     double temp;
//     double z_x = 0;
//     double z_y = 0;
//     int result;

//     while ((z_x * z_x + z_y * z_y <= 4) && (iter < fractal->iter))
//     {
//         temp = z_x * z_x - z_y * z_y + fractal->c_re;
//         z_y = 2.0 * z_x * z_y + fractal->c_i;
//         z_x = temp;
//         iter++;
//     }

//     if (iter == fractal->iter)
//         return 0x000000;
//     result = iter * fractal->color; // fixed
//     return result;
// }

// static void init_value(t_fract *fractal)
// {
//     fractal->scale = WIDTH / (fractal->zoom * 4);
//     fractal->z_x = 0;
//     fractal->z_y = 0;
//     mlx_clear_window(fractal->mlx, fractal->win);
// }

// void mandelbrot_set(t_fract *fractal)
// {
//     int color;
//     int new_y = 0;
//     int new_x;

//     init_value(fractal);
//     while (new_y < HEIGHT)
//     {
//         new_x = 0;
//         while (new_x < WIDTH)
//         {
//             fractal->c_re = fractal->x + (new_x - WIDTH / 2) / fractal->scale;
//             fractal->c_i = fractal->y + (new_y - HEIGHT / 2) / fractal->scale;
//             color = calculate_mandelbrot_color(fractal);
//             ((int *)fractal->addr)[new_y * WIDTH + new_x] = color;
//             new_x++;
//         }
//         new_y++;
//     }
// }