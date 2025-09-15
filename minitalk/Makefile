# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gvasylie <gvasylie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/15 12:51:00 by gvasylie          #+#    #+#              #
#    Updated: 2025/09/15 12:51:45 by gvasylie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
PRINTF = ./printf/libftprintf.a
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_BONUS_SRCS = client_bonus.c
SERVER_BONUS_SRCS = server_bonus.c
CLIENT_BONUS_NAME = client_bonus
SERVER_BONUS_NAME = server_bonus

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_SRCS) $(PRINTF)

$(SERVER_NAME): $(SERVER_SRCS) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(SERVER_SRCS) $(PRINTF)

$(CLIENT_BONUS_NAME): $(CLIENT_BONUS_SRCS) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(CLIENT_BONUS_SRCS) $(PRINTF)

$(SERVER_BONUS_NAME): $(SERVER_BONUS_SRCS) $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $(SERVER_BONUS_SRCS) $(PRINTF)

$(PRINTF):
	$(MAKE) -C ./printf

clean:
	$(MAKE) -C ./printf clean
	rm -f *.o

fclean: clean
	$(MAKE) -C ./printf fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

re: fclean all

bonus: $(CLIENT_BONUS_NAME) $(SERVER_BONUS_NAME)

.PHONY: all clean fclean re bonus