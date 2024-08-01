/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:15:20 by mjakowic          #+#    #+#             */
/*   Updated: 2024/08/01 17:31:08 by dtoszek          ###   ########.fr       */
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

static	int		size_args(char **as)
{
	int		size;

	size = 0;
	while (as[size])
		size++;
	return (size);
}

int				md_echo(char **as)
{
	int		i;
	int		n_option;

	i = 1;
	n_option = 0;
	if (size_args(as) > 1)
	{
		while (as[i] && ft_strcmp(as[i], "-n") == 0)
		{
			n_option = 1;
			i++;
		}
		while (as[i])
		{
			ft_putstr_fd(as[i], 1);
			if (as[i + 1] && as[i][0])
				write(1, " ", 1);
			i++;
		}
	}
	if (n_option == 0)
		write(1, "\n", 1);
	return (1);
}
