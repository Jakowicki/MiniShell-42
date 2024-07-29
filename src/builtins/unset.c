/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjakowic <mjakowic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:57:09 by dtoszek           #+#    #+#             */
/*   Updated: 2024/07/29 18:06:02 by mjakowic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	md_unset(t_env **lst, char **key)
{
	t_env *envlist;
	t_env *prev;
	t_env *temp;
	int i;
	i = 1;

	while (key[i])
	{
		envlist = *lst;
		prev = NULL;

		while (envlist)
		{
			if (!strcmp(key[i], envlist->key))
			{
				if (prev == NULL)
					*lst = envlist->next;
				else
					prev->next = envlist->next;
				temp = envlist;
				envlist = envlist->next;
				free(temp->key);
				free(temp->value);
				free(temp);
				return (1);
			}
			prev = envlist;
			envlist = envlist->next;
		}
		i++;
	}
	return (0);
}
