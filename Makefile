makeNAME = MiniShell
CC = clang
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -I inc
LIBFT = libs/libft/libft.a
LIBS = $(LIBFT) $(FT_PRINTF) -lreadline -lm -g
Files =		src/main \
 					src/tokens/tokens \
					src/tokens/token_handl \
					src/tokens/token_util \
					src/tokens/token_list_ft \
					src/parse/parse_nodes \
					src/parse/parse_text \
					src/parse/parse \
					src/parse/parse_utils \

SRCS = $(Files:%=%.c)
OBJS = $(Files:%=%.o)

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

