NAME = MiniShell
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I inc
LIBFT = libs/libft/libft.a
LIBS = $(LIBFT) $(FT_PRINTF) -lreadline -lm -g
SRCS = $(wildcard src/*.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(INCLUDES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(LIBFT):
	make -C libs/libft

clean:
	make -C libs/libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libs/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

