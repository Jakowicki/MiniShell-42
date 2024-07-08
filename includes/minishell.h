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

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
} t_env;

typedef struct s_minishell
{
	char		*line;
	t_token		*tokens;
	t_token		*curr_token;
	char		**enviro;
	t_env		*envlst;
	int			stdin;
	int			stdout;
	struct termios	original_term;
	int			exit_s;
} t_minishell;

extern t_minishell	g_minishell;

# endif