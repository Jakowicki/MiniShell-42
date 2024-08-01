/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 04:47:19 by dtoszek           #+#    #+#             */
/*   Updated: 2024/08/01 13:07:57 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	ft_sigint_handler(int num)
{
	(void)num;
	if (md_signal.signint_child)
	{
		ft_putstr_fd("\n", 1);
		md_signal.signint_child = false;
		md_signal.heredoc_sigint = true;
	}
	else
	{
		ft_putstr_fd("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_sigquit_handler(int num)
{
	(void)num;
	ft_putstr_fd("Quit: 3\n", 1);
}

void	ft_init_signals(t_content *minishell)
{
	struct termios termin;

	termin = minishell->terminal;
	termin.c_lflag &= ~ECHOCTL;
	tcsetattr(STDERR_FILENO, TCSANOW, &termin);
	md_signal.heredoc_sigint = false;
	md_signal.signint_child = false;
	signal(SIGINT, ft_sigint_handler);
	signal(SIGQUIT, SIG_IGN);
}
