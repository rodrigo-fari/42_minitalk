# Makefile settings
MAKEFLAGS += -s

# Compiler and flags
CC = cc
FLAGS = -Wall -Wextra -Werror

# Project names
NAME = server client
NAME_BONUS = server_bonus client_bonus

# Directories and libraries
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

# Source files for server and client
SERVER_SRCS = server.c utils.c
CLIENT_SRCS = client.c utils.c

# Object files
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

# Default target: Compile everything
all: $(NAME)
	@clear
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Compiled Successfully!║"
	@echo "╚══════════════════════════╝"

# Linking the final executables
$(NAME): $(LIBFT) $(SERVER_OBJS) $(CLIENT_OBJS)
	$(CC) $(FLAGS) -o server $(SERVER_OBJS) $(LIBFT)
	$(CC) $(FLAGS) -o client $(CLIENT_OBJS) $(LIBFT)

# Building the libft library
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Rule to compile object files from source files
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

# Cleaning object files
clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Full cleanup, including executables and library
fclean: clean
	rm -rf server client server_bonus client_bonus
	rm -rf $(LIBFT)
	@clear
	@echo "╔══════════════════════════╗"
	@echo "║ ✅ Cleaned Successfully! ║"
	@echo "╚══════════════════════════╝"

# Rebuild everything from scratch
re: fclean all

# Leak testing using Valgrind
leak: re
	valgrind --leak-check=full --show-leak-kinds=all ./server

# Phony targets to avoid filename conflicts
.PHONY: all clean fclean re bonus leak
