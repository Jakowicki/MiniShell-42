/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:57:24 by dtoszek           #+#    #+#             */
/*   Updated: 2024/07/23 13:47:16 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_node	*ft_check_and_comb(t_content *minishell)
{
	if (minishell->error)
		return (NULL);
	if (minishell->free_token->type == T_PIPE)
		return (NULL); // "parse err wrong syntax(pipe at a beggining)", 
	return (ft_get_text_command(minishell));
}


t_node	*ft_start_parse(t_content *minishell)
{
	t_node		*left;
	t_node		*right;

	if (!minishell->free_token || minishell->error)
		return (NULL);
	left = ft_check_and_comb(minishell);
	if (!left)
		return (NULL);
	while (check_for_pipe_and_token(minishell))
	{
		ft_get_next_token(minishell);
		if (!minishell->free_token)
			return (left); //"parse err(no input after pipe)"
		right = ft_start_parse(minishell);
		if (!right)
			return (left);
		left = ft_combine(left, E_PIPE, right, minishell);
		if (!left)
			return (NULL); //"clear left and right pointeer"
	}
	return (left);
}

t_node	*ft_combine(t_node *left, t_node_type operator, t_node *right,
					t_content *minishell)
{
	t_node *node;

	if (minishell->error)
	{
		return (NULL);
	}
	node = get_new_node(operator);
	if (!node)
	{
		return (NULL);
	} //"set parse err(wrong memory alloc)"
	node->left = left;
	node->right = right;
	return (node);
}

t_node	*ft_parse(t_content *minishell)
{
	t_node	*parsed;

	minishell->free_token = minishell->tokens;
	parsed = ft_start_parse(minishell);
	if (minishell->free_token)
	{
		return(NULL); //error
	}
	return (parsed);
}