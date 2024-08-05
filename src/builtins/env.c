/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:02:16 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/05 17:33:23 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_extract_key(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (GC_collector(ft_substr(str, 0, i), false));
		i++;
	}
	return (ft_strdup(str));
}

char	*ft_extract_value(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			return (GC_collector(ft_substr(str, i, ft_strlen(str) - i), false));
		}
		i++;
	}
	return (NULL);
}

void	ft_init_env(t_content *minishell)
{
	int		i;
	char	**env;
	char	*key;
	char	*value;

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

int	md_env(t_content *minishell)
{
	t_env	*replic;

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
