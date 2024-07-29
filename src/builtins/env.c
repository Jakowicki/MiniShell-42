/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:17:53 by mjakowic          #+#    #+#             */
/*   Updated: 2024/07/29 13:43:34 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_extract_key(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return(ft_substr(str, 0 , i));
		i++;
	}
	return (ft_strdup(str));
}

static char	*ft_extract_value(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (ft_substr(str, i , ft_strlen(str) - i));
		}
		i++;
	}
	return (NULL);
}


void ft_init_env(t_content *minishell)
{
	int i;
	char **env;
	char *key;
	char *value;
	
	i = 0;
	env = minishell->envir;
	while (env[i])
	{
		key = ft_extract_key(env[i]);
		value = ft_extract_value(env[i]);
		ft_update_env_list(key, value, true, minishell);
		i++;
	}
}

int md_env(t_content *minishell)
{
	t_env *replic;
	replic = minishell->enviroment;
	while (replic)
	{
		printf("%s=%s\n", replic->key, replic->value);
		replic = replic->next;
	}
	if (replic)
		printf("%s=%s\n", replic->key, replic->value);
	return (1);
}