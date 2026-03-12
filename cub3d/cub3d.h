/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavrank <ahavrank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 21:00:01 by ahavrank          #+#    #+#             */
/*   Updated: 2026/03/03 21:19:44 by ahavrank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>

# define TEX_NO 0
# define TEX_SO 1
# define TEX_WE 2
# define TEX_EA 3
# define WINDOW_W 700
# define WINDOW_H 500
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ESC_KEY 65307
# define RT_SPEED 0.01
# define MV_SPEED 0.02

typedef struct colours_for_map
{
	int	red;
	int	blue;
	int	green;
}	t_colour;

typedef struct map_informations
{
	int	line_count;
	int	space_count;
	int	map_width;
	int	map_hight;
}	t_map_info;

typedef struct game_player
{
	char	direction;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				width;
	int				height;
	int				line_length;
	int				bits_per_pixel;
	int				endian;
}					t_image;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			left;
	int			right;
}					t_keys;

typedef struct s_calc
{
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	side_dist_x;
	double	side_dist_y;
	int		side;
	double	wall_x;
	double	wall_dist;
	int		text_num;
}					t_calc;

typedef struct s_wall
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		tex_y;
}	t_wall;

typedef struct map
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_image		texture[4];
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	t_colour	*f_colour;
	t_colour	*c_colour;
	char		**map;
	char		**head_map;
	t_map_info	*map_info;
	t_player	*player;
	double		old_time;
	double		time;
	int			*collum_size;
	t_keys		key;
	t_calc		calc;
}	t_map;

void	free_map(t_map **map);
void	free_pt3(t_map **map);
void	free_borders_loop(int *space_pos, t_map **map);
void	free_colours(char *line, t_map **map);
void	print_struct(t_map **map);
void	free_strings(char **strings, int count);
char	*texture_value(char *line);
int		parsing_elements_textures(char *line, t_map **map);
int		parsing_elements_textures_cnt(char *line, t_map **map);
int		parsing_elements_colours(char *line, t_map **map);
int		parsing_elements_colours_cnt(char *line, t_map **map);
int		parse_crossroad(char *argv, t_map **map);
int		parse_map(char *line, t_map **map);
int		part_of_map(char *line);
int		check_all_borders(t_map **map);
int		part_of_map(char *line);
int		still_border(char *line, int side);
int		find_border(char *line, int side);
int		colour_values(char *line, int colour);
int		part_of_map(char *line);
int		prepare_parse_map(char *line, t_map **map);
int		gibberish_present(char *line);
void	free_in_parsing_map(char *line, t_map **map, char **temp_map);
int		empty_line(char *line);
int		check_first_border(char *line);
int		compare_start_borders(int start, t_map **map, int spot);
int		compare_end_borders(int end, t_map **map, int spot);
void	map_invalid(t_map **map, char *msg);
int		space_inside_present(char *line);
int		borders_around_space(t_map **map, int i);
int		borders_next(char *line);
int		*space_positions(t_map **map, int i);
void	set_head(t_map **map);
void	set_start_colours(t_map **map);
void	set_player(t_map **map);
void	set_map_struct(t_map **map);
int		setup_game(t_map **map);
int		setting_player(t_map **map);
int		setting_direction(t_map **map);
int		setting_direction_cnt(t_map **map);
int		setting_position(t_map **map);
int		setting_plane(t_map **map);
void	run_mlx(t_map *map);
void	render(t_map *map);
void	player_moves(t_map *map, double move_x, double move_y);
int		process_movement(t_map *map);
void	side_dist_init(t_map *map);
void	perform_dda(t_map *map);
void	wall_dist(t_map *map);
void	draw_wall(t_map *map, int x);
void	color_pixel(t_map *map, int x, int y, int color);
char	*trim_n_cleanup(char **strings, char *path);
int		adding_collum_size(t_map **map);
char	*trim_map_line(char *map_line);
int		borders_next_space_loop(t_map **map, int count, int *space_pos, int i);
int		check_player(t_map **map);
int		find_texture_colours(char *line);
int		free_borders_loop_cnt(t_map **map, int k, int *space_pos, int i);

#endif
