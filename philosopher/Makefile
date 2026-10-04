CC = cc
FLAGS = -Wall -Werror -Wextra -g -pthread

SRC_DIR = src/
SRCS = main.c init.c cleanup.c routine.c monitor.c threads.c

SRC = $(addprefix $(SRC_DIR), $(SRCS))
OBJS = $(SRC:.c=.o)

HEADER_PATH = include

NAME = philo

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -I$(HEADER_PATH) -o $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(FLAGS) -I$(HEADER_PATH) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re