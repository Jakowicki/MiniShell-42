/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:44:22 by dtoszek           #+#    #+#             */
/*   Updated: 2024/07/08 15:45:39 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *ft_tokenize(void)
{
	char *line;
	t_token *token_list;

	line = g_minishell.line;
	token_list = ft_tokenization_handler(line);
	free(line);
	g_minishell.line = NULL;
	return (token_list);
}