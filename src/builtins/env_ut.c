/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_ut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:08:21 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/05 15:14:45 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static t_env	*ft_envlist_new(char *key, char *value)
{
	t_env	*new;

	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	if (value)
		new->value = ft_strdup(value);
	new->next = NULL;
	return (new);
}

char	*ft_get_envlst_val(char *key, t_content *minishell)
{
	t_env	*envlst;

	envlst = minishell->enviroment;
	while (envlst)
	{
		if (!ft_strcmp(key, envlst->key))
			return (envlst->value);
		envlst = envlst->next;
	}
	return (NULL);
}

static void	ft_envlist_back(t_env *new, t_content *minishell)
{
	t_env	*curr;

	if (!minishell->enviroment)
	{
		minishell->enviroment = new;
		return ;
	}
	curr = minishell->enviroment;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = new;
}

void	ft_update_env_list(char *key, char *value, bool yes,
		t_content *minishell)
{
	t_env	*envlist;

	envlist = minishell->enviroment;
	while (envlist)
	{
		if (!ft_strcmp(key, envlist->key))
		{
			if (value)
				envlist->value = ft_strdup(value);
			return ;
		}
		envlist = envlist->next;
	}
	if (yes)
		ft_envlist_back(ft_envlist_new(key, value), minishell);
}
