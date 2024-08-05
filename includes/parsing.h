/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 14:24:55 by mjakowic          #+#    #+#             */
/*   Updated: 2024/08/02 14:25:09 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef enum e_node_type
{
	E_COMMAND,
	E_PIPE,
}						t_node_type;

typedef enum e_io_type
{
	E_IN,
	E_OUT,
	E_HEREDOC,
	E_APPEND,
}						t_io_type;

typedef struct s_io_node
{
	t_io_type			type;
	char				*value;
	char				**expanded_value;
	int					here_doc;
	struct s_io_node	*next;
	struct s_io_node	*prev;
}						t_io_node;

typedef struct s_node
{
	t_node_type			type;
	t_io_node			*io_node;
	char				*args;
	char				**expand_args;
	struct s_node		*left;
	struct s_node		*right;
}						t_node;

#endif
