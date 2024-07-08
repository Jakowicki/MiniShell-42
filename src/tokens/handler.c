#include "minishell.h"

int ft_handle_separator(char **line_ptr, t_token **token_list)
{
	if(ft_strncmp(*line_ptr, "<<", 2))
		return (ft_append_separetor(T_DLESS, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, ">>", 2))
		return (ft_append_separetor(T_DGREAT, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, "<", 1))
		return (ft_append_separetor(T_LESS, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, ">", 1))
		return (ft_append_separetor(T_GREAT, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, "(", 1))
		return (ft_append_separetor(T_O_PARENT, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, ")", 1))
		return (ft_append_separetor(T_C_PARENT, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, "&&", 2))
		return (ft_append_separetor(T_AND, line_ptr, token_list) && 1);
	else if (!ft_strncmp(*line_ptr, "||", 2))
		return (ft_append_separetor(T_OR, line_ptr, token_list) && 1);
	else
		return (ft_append_separetor(T_PIPE, line_ptr, token_list) && 1);
}

t_token *ft_tokenizaton_handler(char *line)
{
	int error;
	t_token *token_list;
	
	error = 0;
	token_list = NULL;
	while(*line)
	{
		if(error)
			return(ft_clear_token_list(&token_list), NULL);
		if (ft_isspace(*line))
			ft_skip_space(&line);
		else if (!ft_strncmp(line, "<", 1) || !ft_strncmp(line, ">", 1)
			|| !ft_strncmp(line, "|", 1) || !ft_strncmp(line, "&&", 2)
			|| !ft_strncmp(line, "(", 1) || !ft_strncmp(line, ")", 1))
			error = (!ft_handle_separator(&line, &token_list) && 1);
		else
			error = (!ft_append_identifier(&line, &token_list) && 1);	
	}
	return (token_list);
}