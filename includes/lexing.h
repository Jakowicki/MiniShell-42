#ifndef LEXING_H
# define LEXING_H

# include <stdbool.h>

# define PROMPT "MDshell > "

typedef enum e_token_type
{
	T_TEXT,
	T_LESS,
	T_GREAT,
	T_DLESS,
	T_DGREAT,
	T_PIPE,
	T_NONE,
}	t_token_type;


typedef	struct s_tokens
{
	t_token_type	type;
	char			*value;
	t_token			*next;
	t_token			*prev;
}	t_token;

#endif
