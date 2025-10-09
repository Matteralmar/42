# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/06 10:09:36 by gvasylie          #+#    #+#              #
#    Updated: 2025/10/06 10:09:36 by gvasylie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
SERVER_SRC = server.c
CLIENT_SRC = client.c 
SERVER_OBJ = server.o
CLIENT_OBJ = client.o
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
SERVER_SRC_BONUS = server_bonus.c
CLIENT_SRC_BONUS = client_bonus.c 
SERVER_OBJ_BONUS = server_bonus.o
CLIENT_OBJ_BONUS = client_bonus.o
CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(SERVER) $(CLIENT)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(SERVER): $(SERVER_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(SERVER_OBJ): $(SERVER_SRC)
	$(CC) $(CFLAGS) -c $<

$(CLIENT): $(CLIENT_OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(CLIENT_OBJ): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -c $<

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_OBJ_BONUS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(SERVER_OBJ_BONUS): $(SERVER_SRC_BONUS)
	$(CC) $(CFLAGS) -c $<

$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(CLIENT_OBJ_BONUS): $(CLIENT_SRC_BONUS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re libft
