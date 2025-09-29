# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/29 11:28:25 by gvasylie          #+#    #+#              #
#    Updated: 2025/09/29 11:28:25 by gvasylie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc
FLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
SRC_CLIENT = client.c
SRC_SERVER = server.c
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c
LIBFT = ./libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) -o $(CLIENT) $(SRC_CLIENT) $(LIBFT)
	$(CC) -o $(SERVER) $(SRC_SERVER) $(LIBFT)
clean:
	make clean -C ./libft
	rm -rf *.o 
fclean:
	make fclean -C ./libft
	rm -rf *.o client server client_bonus server_bonus
bonus:
	make -C ./libft
	$(CC) -o $(CLIENT_BONUS) $(SRC_CLIENT_BONUS) $(LIBFT)
	$(CC) -o $(SERVER_BONUS) $(SRC_SERVER_BONUS) $(LIBFT)
re: fclean all

.PHONY: all clean fclean re