/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:05:39 by mjakowic          #+#    #+#             */
/*   Updated: 2024/08/01 18:24:05 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int md_pwd()
{
    char cwd[PATH_MAX];

    if(getcwd(cwd, PATH_MAX))
    {
        ft_putendl_fd(cwd, 1);
        return (1);
    }
    else
        return (0);
}
