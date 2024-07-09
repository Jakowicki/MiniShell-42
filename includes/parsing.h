#ifndef PARSING_H
# define PARSING_H

typedef enum e_node_type
{
	N_PIPE,
	N_AND,
	N_OR,
	N_CMD,
}	t_node_type;

typedef enum e_io_type
{
	IO_IN,
	IO_OUT,
	IO_HEREDOC,
	IO_APPEND,
}	t_io_type;

typedef enum e_parse_err_type
{
	E_MEM = 1,
	E_SYNTAX,
}	t_parse_err_type;

typedef struct s_io_node
{
	t_io_type			type;
	char				*value;
	char				**expanded_value;
	int					here_doc;
	struct s_io_node	*prev;
	struct s_io_node	*next;
} t_io_node;


typedef struct s_node
{
	t_node_type		type;
	t_io_node		*io_list;
	char			*args;
	char			**expanded_args;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_parse_err
{
	t_parse_err_type	type;
	char				*str;
}	t_parse_err;


# endif