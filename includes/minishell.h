#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libs/libft/libft.h"
# include <signal.h>
# include "colors.h"
# include "lexing.h"
# include "parsing.h"
# include <sys/wait.h>
# include <termios.h>
# include <dirent.h>
# include <stdbool.h>


typedef struct s_content
{
	char		*line;
	t_token		*tokens;
} t_content;

# endif
