/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:24:59 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/01 18:06:10 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_exec_builtin(char **args, t_content *minishell)
{
	if (ft_strcmp(args[0], "echo") == 0)
		return (md_echo(args));
	if (ft_strcmp(args[0], "cd") == 0)
		return (md_cd(args, minishell));
	if (ft_strcmp(args[0], "env") == 0)
		return (md_env(minishell));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (md_pwd());
	if (ft_strcmp(args[0], "unset") == 0)
		return (md_unset(&minishell->enviroment, args));
	return (ENO_GENERAL);
}

bool	ft_is_builtin(char *arg)
{
	if (!arg)
		return (false);
	if (!ft_strcmp(arg, "echo")
		|| !ft_strcmp(arg, "cd")
		|| !ft_strcmp(arg, "exit")
		|| !ft_strcmp(arg, "pwd")
		|| !ft_strcmp(arg, "export")
		|| !ft_strcmp(arg, "unset")
		|| !ft_strcmp(arg, "env"))
		return (true);
	return (false);
}
