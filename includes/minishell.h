#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/libft/libft.h"
# include "colors.h"
# include "lexing.h"
# include "parsing.h"
# include <dirent.h>
# include <errno.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/wait.h>
# include <termios.h>

# ifndef PATH_MAX
#  define PATH_MAX 4096
# endif

typedef struct s_env
{
	char			*value;
	char			*key;
	struct s_env	*next;
}					t_env;

typedef struct s_content
{
	char			*line;
	char			**envir;
	t_token			*tokens;
	t_token			*free_token;
	int				exit_state;
	t_node			*parsed;
	t_env			*enviroment;
	int				error;
}					t_content;

t_token				*ft_tokens(t_content *minishell);
t_token				*ft_tokens_handle(char *line, t_content *minishell);
t_node				*ft_parse(t_content *minishell);
t_node				*ft_start_parse(t_content *minishell);
t_node				*ft_check_and_comb(t_content *minishell);
t_node				*ft_combine(t_node *left, t_node_type operator, t_node
						* right, t_content *minishell);
t_io_type			ft_get_io_type(t_token_type type);
void				ft_get_next_token(t_content *minishell);
int					ft_is_redirector(t_token_type type);
t_node				*ft_get_text_command(t_content *minishell);
t_node				*get_new_node(t_node_type type);
t_io_node			*ft_add_io_node(t_token_type type, char *value);
void				ft_connect_io_node(t_io_node **nodes, t_io_node *new);
t_io_node			*ft_add_io_node(t_token_type type, char *value);
bool				check_for_pipe_and_token(t_content *minishell);
int					md_pwd(void);
int					md_echo(char **as);
int md_env(t_content *minishell);
int					md_cd(char **args, t_content *minishell);
int					md_unset(t_env **lst, char **key);
void				ft_update_env_list(char *key, char *value, bool yes,
						t_content *minishell);
void				ft_init_env(t_content *minishell);

#endif
