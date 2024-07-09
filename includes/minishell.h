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

typedef enum e_err_msg
{
	ERRMSG_CMD_NOT_FOUND,
	ERRMSG_NO_SUCH_FILE,
	ERRMSG_PERM_DENIED,
	ERRMSG_AMBIGUOUS,
	ERRMSG_TOO_MANY_ARGS,
	ERRMSG_NUMERIC_REQUI
}	t_err_msg;

typedef enum e_err_no
{
	ENO_SUCCESS,
	ENO_GENERAL,
	ENO_CANT_EXEC = 126,
	ENO_NOT_FOUND,
	ENO_EXEC_255 = 255
}	t_err_no;

typedef enum e_ast_direction
{
	TD_LEFT,
	TD_RIGHT
}	t_ast_direction;

typedef struct s_err
{
	t_err_no	no;
	t_err_msg	msg;
	char		*cause;
}	t_err;

typedef struct s_path
{
	t_err	err;
	char	*path;
}	t_path;

typedef struct s_minishell
{
	char		*line;
	t_token		*tokens;
	t_token		*curr_token;
	t_node		*ast;
	t_parse_err	parse_err;
	char		**enviro;
	t_env		*envlst;
	int			stdin;
	int			stdout;
	struct termios	original_term;
	int			exit_s;
} t_minishell;

extern t_minishell	g_minishell;

# endif