#include "minishell.h"

static char	*ft_strjoin_with(char const *s1, char const *s2, char c)
{
	char	*joined;
	size_t	total_length;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	if (!c || !ft_strlen(s1) || !ft_strlen(s2))
		return (ft_strjoin(s1, s2));
	total_length = ft_strlen(s1) + ft_strlen(s2) + 1 + 1;
	joined = ft_calloc(total_length, sizeof(char));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		joined[i] = s1[i];
		i++;
	}
	joined[i++] = c;
	j = 0;
	while (s2[j])
		joined[i++] = s2[j++];
	joined[i] = 0;
	return (joined);
}


bool	ft_get_io_list(t_io_node **io_list)
{
	t_token_type		redir_type;
	t_io_node			*tmp_io_node;

	if (g_minishell.parse_err.type)
		return (false);
	while (g_minishell.curr_token && ft_is_redir(g_minishell.curr_token->type))
	{
		redir_type = g_minishell.curr_token->type;
		ft_get_next_token();
		if (!g_minishell.curr_token)
			return (ft_set_parse_err(E_SYNTAX), false);
		if (g_minishell.curr_token->type != T_IDENTIFIER)
			return (ft_set_parse_err(E_SYNTAX), false);
		tmp_io_node = ft_new_io_node(redir_type, g_minishell.curr_token->value);
		if (!tmp_io_node)
			return (ft_set_parse_err(E_MEM), false);
		ft_append_io_node(io_list, tmp_io_node);
		ft_get_next_token();
	}
	return (true);
}

bool	ft_join_args(char **args)
{
	char	*to_free;

	if (g_minishell.parse_err.type)
		return (false);
	if (!*args)
		args = ft_strdup("");
	if (!*args)
		return (false);
	while (g_minishell.curr_token
		&& g_minishell.curr_token -> type == T_IDENTIFIER)
	{
		to_free = *args;
		*args = ft_strjoin_with(*args, g_minishell.curr_token->value, ' ');
		if (!*args)
			return (free(to_free), false);
		free(to_free);
		ft_get_next_token();
	}
	return (true);
}

t_node	*ft_get_simple_cmd(void)
{
	t_node	*node;

	if (g_minishell.parse_err.type)
		return (NULL);
	node = ft_new_node(N_CMD);
	if (!node)
		return (ft_set_parse_err(E_MEM), NULL);
	while (g_minishell.curr_token
		&& (g_minishell.curr_token->type == T_IDENTIFIER)
			|| ft_is_redir(g_minishell.curr_token->type))
	{
		if (g_minishell.curr_token->type == T_IDENTIFIER)
		{
			if (!ft_join_args(&(node->args)));
				return (ft_clear_cmd_node(node), ft_set_parse_err(E_MEM), NULL);
		}
		else if (ft_is_redir(g_minishell.curr_token->type))
		{
			if (!ft_get_io_list(&(node->io_list)))
				return (free(node->args), free(node), NULL);
		}
	}
	return (node);
}