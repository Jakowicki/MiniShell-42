/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:06:06 by mjakowic          #+#    #+#             */
/*   Updated: 2024/08/01 18:23:51 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif

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


static void print_error(char **as)
{
	ft_putstr_fd("cd: ", 2);
	if (as[2])
		ft_putstr_fd("string not in pwd: ", 2);
	else
	{
		ft_putstr_fd(strerror(0), 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putstr_fd(as[1], 2);
}

static char	*get_env_path(t_content *minishell, const char *var)
{
	t_env	*envlist;

	envlist = minishell->enviroment;
	
	while (envlist)
	{
		if(!ft_strcmp(var, envlist->key))
			return(ft_strdup(envlist->value));
		envlist = envlist->next;
	}
	return (NULL);
}

static int	update_oldpwd(t_content *minishell)
{
	char	cwd[PATH_MAX];
	if (getcwd(cwd, PATH_MAX) == NULL)
		return (0);
	ft_update_env_list("OLDPWD", cwd, false, minishell);
	return (1);
}

static int	go_to_path(int option, t_content *minishell)
{
	t_env	*env;
	int		ret;
	char	*env_path;
	env = minishell->enviroment;
	env_path = NULL;
	if (option == 0)
	{
		update_oldpwd(minishell);
		env_path = get_env_path(minishell, "HOME");
		if (!env_path)
			return (ft_putendl_fd("MDshell : cd: HOME not set", 2), -1);
	}
	else if (option == 1)
	{
		env_path = get_env_path(minishell, "OLDPWD");
		if (!env_path)
		{
			ft_putendl_fd("MDshell : cd: OLDPWD not set", 2);
			return (-1);
		}
		update_oldpwd(minishell);
	}
	ret = chdir(env_path);
	free(env_path);
	return (ret);
}

int	md_cd(char **args, t_content *minishell)
{
	int cd_ret;

	if (!args[1])
		return (go_to_path(0, minishell));
	if (ft_strcmp(args[1], "-") == 0)
		cd_ret = go_to_path(1, minishell);
	else
	{
		update_oldpwd(minishell);
		cd_ret = chdir(args[1]);
		if (cd_ret < 0)
			cd_ret *= -1;
		if (cd_ret != 0)
			print_error(args);
	}
	return (cd_ret);
}