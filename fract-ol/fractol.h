/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:05:27 by gvasylie          #+#    #+#             */
/*   Updated: 2025/09/26 12:41:55 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct  s_fract {
    void    *mlx;
    void    *win;
    void    *img;
    void    *addr;
    int     bits_per_pixel;
    int     line_len;
    int     endian;
    double  zoom;
    double  x;
    double  y;
    int     iter;
    double  c_re;
    double  c_i;
    int     type;
    int     color;
    double  z_x;
	double  z_y;
    double	scale;
}   t_fract;

void	init_fractal(t_fract *fractal);
void	error_msg(int i);
void    draw(t_fract *fractal);
int     what_set(t_fract *fractal, char **av);
int     destroy(t_fract *fractal);
int     action(int action, t_fract *fractal);
int     mouse_hook(int button, int x, int y, void *param);
void    hooks(t_fract *fractal);
void    mandelbrot_set(t_fract *fractal);
#endif