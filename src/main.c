/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:43:46 by dtoszek           #+#    #+#             */
/*   Updated: 2024/07/15 16:15:21 by dtoszek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void ft_minishell_loop(t_content *minishell)
{
	while (1)
	{
		minishell->line = readline(PROMPT);
		if (minishell->line == NULL || !strcmp(minishell->line, "exit"))
		{
			printf("exit");
			exit(0);
		}
		if (minishell->line)
			add_history(minishell->line);
		minishell->tokens = ft_tokens(&minishell);
		
	}

}

static void ft_init_minishell(t_content *minishell)
{
	(void)minishell;
}


int main(int argc, char **argv, char **env)
{
	t_content minishell;

	((void)argv, (void)argc, (void)env);
	ft_init_minishell(&minishell);
	ft_minishell_loop(&minishell);

	return (0);
}