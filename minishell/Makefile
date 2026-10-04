# ───────────────────────────
# Minishell — complete Makefile
# ───────────────────────────

NAME		:= minishell

# toolchain & flags
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -Iinclude -I. -I$(LIBFT_DIR)
DEPFLAGS	:= -MMD -MP

# layout
SRC_DIR		:= src
OBJ_DIR		:= build

# third-party libs
LIBFT_DIR  := libft
LIBFT      := $(LIBFT_DIR)/libft.a

# linker flags (adjust READLINE on macOS if needed)
LDFLAGS    := -L$(LIBFT_DIR)
LDLIBS     := -lft -lreadline

READLINE_DIR = /opt/homebrew/opt/readline

CFLAGS += -I$(READLINE_DIR)/include
LDFLAGS += -L$(READLINE_DIR)/lib

include sources.mk

# objects & deps (mirror src/ tree under build/)
OBJS       := $(CFILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS       := $(OBJS:.o=.d)

# ───────────────────────────
# default target
# ───────────────────────────

.PHONY: all
all: $(NAME)

# link
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

# compile (creates obj subdirs; writes .d next to .o)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

# libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# ───────────────────────────
# utilities
# ───────────────────────────

.PHONY: clean fclean re libft print-cfiles

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

libft: $(LIBFT)

# include auto-generated header dependencies (safe if missing)
-include $(DEPS)
