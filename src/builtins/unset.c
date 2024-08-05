/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:57:09 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/05 15:14:39 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	md_unset(t_env **lst, char **key)
{
	t_env	*envlist;
	t_env	*temp;
	int		i;

	i = 1;
	while (key[i])
	{
		envlist = *lst;
		temp = NULL;
		while (envlist)
		{
			if (!ft_strcmp(key[i], envlist->key))
			{
				if (temp)
					temp->next = envlist->next;
				else
					*lst = envlist->next;
			}
			temp = envlist;
			envlist = envlist->next;
		}
		i++;
	}
	return (0);
}
