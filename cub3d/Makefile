NAME = cub3D
SOURCES = main.c\
			parsing/parsing.c\
			parsing/parsing_utils.c\
			parsing/parse_map.c\
			parsing/parse_map_utils.c\
			parsing/parse_map_borders.c\
			parsing/parse_map_borders_utils.c\
			parsing/parse_colours.c\
			parsing/parse_colours_utils.c\
			parsing/parse_textures.c\
			parsing/set_struct.c\
			parsing/print_struct.c\
			parsing/for_exit.c\
			parsing/parse_player.c\
			free_stuff.c\
			rendering/setup_game.c\
			rendering/setting_player.c\
			rendering/render_ray.c\
			rendering/run_game.c\
			rendering/movement.c\
			rendering/dda_calc.c\
			rendering/draw_wall.c

LIBFTLIB = libft/libft.a

OBJS = $(SOURCES:.c=.o)
CC = cc
CFLAGS =  -Wall -Werror -Wextra -g 

MLX_DIR = minilibx-linux
MLXLIB = $(MLX_DIR)/libmlx.a
MLXFLAGS = -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLXLIB) $(LIBFTLIB) $(MLXFLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
