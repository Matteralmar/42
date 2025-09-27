# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/18 14:01:32 by gvasylie          #+#    #+#              #
#    Updated: 2025/09/27 13:47:05 by gvasylie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAGS = -L ./mlx -lmlx -I./mlx -lXext -lX11
LIBFT = ./libft/libft.a

SRC = fract-ol.c \
	hooks.c \
	mandelbro.c \
	newtons_julienne.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) -lm $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I./mlx -I./libft -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

