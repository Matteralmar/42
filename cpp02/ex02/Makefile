NAME = fixed

COMP = c++

FLAGS = -Wall -Wextra -Werror

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

CPP_FLAGS = -std=c++98

$(NAME): $(OBJ)
	$(COMP) $(OBJ) $(CPP_FLAGS) $(FLAGS) -o $(NAME)

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re