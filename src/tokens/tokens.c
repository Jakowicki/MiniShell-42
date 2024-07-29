/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:30:05 by dtoszek           #+#    #+#             */
/*   Updated: 2024/07/16 15:55:00 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*ft_tokens(t_content *minishell)
{
	char	*line;
	t_token	*tokens;

	line = minishell->line;
	tokens = ft_tokens_handle(line, minishell);
	free(line);
	minishell->line = NULL;
	return (tokens);
}
