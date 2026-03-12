CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

LIBFT_SRCS = ../libft/libft/ft_atoi.c ../libft/libft/ft_bzero.c ../libft/libft/ft_calloc.c ../libft/libft/ft_isalnum.c ../libft/libft/ft_isalpha.c \
 ../libft/libft/ft_isascii.c ../libft/libft/ft_isdigit.c ../libft/libft/ft_isprint.c ../libft/libft/ft_itoa.c ../libft/libft/ft_memchr.c \
 ../libft/libft/ft_memcmp.c ../libft/libft/ft_memcpy.c ../libft/libft/ft_memmove.c ../libft/libft/ft_memset.c ../libft/libft/ft_putchar_fd.c \
 ../libft/libft/ft_putendl_fd.c ../libft/libft/ft_putnbr_fd.c ../libft/libft/ft_putstr_fd.c ../libft/libft/ft_split.c \
 ../libft/libft/ft_strchr.c ../libft/libft/ft_strdup.c ../libft/libft/ft_striteri.c ../libft/libft/ft_strjoin.c ../libft/libft/ft_strlcat.c ../libft/libft/ft_strlcpy.c \
 ../libft/libft/ft_strlen.c ../libft/libft/ft_strmapi.c ../libft/libft/ft_strncmp.c ../libft/libft/ft_strnstr.c ../libft/libft/ft_strrchr.c \
 ../libft/libft/ft_strtrim.c ../libft/libft/ft_substr.c ../libft/libft/ft_tolower.c ../libft/libft/ft_toupper.c ../libft/libft/ft_lstadd_back.c \
 ../libft/libft/ft_lstadd_front.c ../libft/libft/ft_lstclear.c ../libft/libft/ft_lstdelone.c ../libft/libft/ft_lstiter.c \
 ../libft/libft/ft_lstlast.c ../libft/libft/ft_lstmap.c ../libft/libft/ft_lstnew.c ../libft/libft/ft_lstsize.c
LIBFT_OBJ = $(LIBFT_SRCS:.c=.o)

PRINTF_SRCS = ../libft/ft_printf/ft_funcs_printf.c ../libft/ft_printf/ft_printf.c
PRINTF_OBJ = $(PRINTF_SRCS:.c=.o)

GNL_SRCS = ../libft/get_next_line/get_next_line.c ../libft/get_next_line/get_next_line_utils.c
GNL_OBJ = $(GNL_SRCS:.c=.o)

INCS = -I. -Ift_printf -Iget_next_line

AR = ar rcs

all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	$(AR) $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

clean:
	rm -f $(LIBFT_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re