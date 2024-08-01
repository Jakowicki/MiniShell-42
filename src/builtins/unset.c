/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:57:09 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/01 17:39:19 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	md_unset(t_env **lst, char **key)
{
	t_env	*envlist;
	t_env	*temp;
	
	int i = 1;
	while (key[i])
	{
		envlist = *lst;
		temp = NULL;
		while(envlist)
		{
			if(!ft_strcmp(key[i], envlist->key))
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