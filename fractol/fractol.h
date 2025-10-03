/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:05:27 by gvasylie          #+#    #+#             */
/*   Updated: 2025/10/03 13:50:51 by gvasylie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

# define BLACK 0x000000
# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define WID_HEI 500
# define COLOR 0xe6ccff
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307
# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	double	zoom;
	double	x;
	double	y;
	int		iter;
	double	c_re;
	double	c_i;
	int		type;
	int		color;
	double	z_x;
	double	z_y;
	double	scale;
}	t_fract;

int		destroy(t_fract *fractal);
void	draw(t_fract *fractal);
void	hooks(t_fract *fractal);
void	mandelbrot_set(t_fract *fractal);
void	newton_julia_set(t_fract *fractol);
int		color_calc(t_fract *fractol, double x, double y);
#endif