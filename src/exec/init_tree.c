/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 02:04:34 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/01 18:05:23 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	ft_is_delimiter(char *delimiter, char *str)
{
	while (*str)
	{
		if (*delimiter == '"' || *delimiter == '\'')
		{
			delimiter++;
			continue ;
		}
		else if (*str == *delimiter)
		{
			str++;
			delimiter++;
		}
		else
			return (false);
	}
	while (*delimiter == '"' || *delimiter == '\'')
		delimiter++;
	return (!*delimiter);
}

static void	ft_heredoc_sigint_handler(int signum)
{
	(void)signum;
	//ft_clean_ms();
	exit(SIGINT);
}

void	ft_heredoc(t_io_node *io, int p[2], t_content *minishell)
{
	char	*line;
	char	*quotes;

	signal(SIGINT, ft_heredoc_sigint_handler);
	quotes = io->value;
	while (*quotes && *quotes != '"' && *quotes != '\'')
		quotes++;
	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_is_delimiter(io->value, line))
			break ;
		if (!quotes)
			ft_heredoc_expander(line, p[1], minishell);
		else
		{
			ft_putstr_fd(line, p[1]);
			ft_putstr_fd("\n", p[1]);
		}
	}
	//ft_clean_ms();
	exit(0);
}

static bool ft_leave_leaf(int p[2], int *pid)
{
	waitpid(*pid, pid, 0);
	signal(SIGQUIT, ft_sigquit_handler);
	md_signal.signint_child = false;
	close(p[1]);
	if (WIFEXITED(*pid) && WEXITSTATUS(*pid) == SIGINT)
		return (true);
	return (false);
}

static void	ft_init_leaf(t_content *minishell, t_node *node)
{
	t_io_node	*io;
	int			p[2];
	int			pid;

	if (node->args)
		node->expand_args = ft_expand(node->args, minishell);
	io = node->io_node;
	while (io)
	{
		if (io->type == E_HEREDOC)
		{
			pipe(p);
			md_signal.signint_child = true;
			pid = (signal(SIGQUIT, SIG_IGN), fork());
			if (!pid)
				ft_heredoc(io, p, minishell);
			if (ft_leave_leaf(p, &pid))
				return ;
			io->here_doc = p[0];
		}
		io->expanded_value = ft_expand(io->value, minishell);
		io = io->next;
	}
	return ;
}

void	ft_init_tree(t_content *minishell, t_node *node)
{

	if (!node)
		return ;
	if (node->type == E_PIPE)
	{
		ft_init_tree(minishell, node->left);
		if (!md_signal.heredoc_sigint)
			ft_init_tree(minishell, node->right);
	}
	else
		ft_init_leaf(minishell, node);
}
