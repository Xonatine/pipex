NAME = pipex
SOURCE = ./src/pipex.c \
			./src/utils.c

OBJS = $(SOURCE:.c=.o)

LDFLAGS = -L lib/libft -l ft
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MAKEFLAGS = --no-print-directory

all:$(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C ./lib/libft
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME) -fsanitize=address -g3

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $^ -fsanitize=address -g3

clean:
	@$(MAKE) clean -C ./lib/libft
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C ./lib/libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
#.SILENT: