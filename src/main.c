/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtoszek <dtoszek@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:43:46 by dtoszek           #+#    #+#             */
/*   Updated: 2024/07/23 14:08:24 by dtoszek          ###   ########.fr       */
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
			free(minishell->line);
			printf("exit");
			exit(0);
		}
		if (minishell->line)
			add_history(minishell->line);
		minishell->tokens = ft_tokens(minishell);
		if (!minishell->tokens)
			continue ;
		minishell->parsed = ft_parse(minishell);
		while (minishell->parsed)
		{
			if (minishell->parsed)
				printf("%s | %d\n", minishell->parsed->args, minishell->parsed->type);
			if (minishell->parsed->left)
				printf("%s | %d\n", minishell->parsed->left->args, minishell->parsed->left->type);
			if (minishell->parsed->right)
				printf("%s | %d\n", minishell->parsed->right->args, minishell->parsed->right->type);
			printf("\n\n");
			minishell->parsed = minishell->parsed->left;
		}
		
	}

}

static void ft_init_minishell(t_content *minishell)
{
	(void)minishell;
	minishell->error = 0;
}


int main(int argc, char **argv, char **env)
{
	t_content minishell;

	((void)argv, (void)argc, (void)env);
	ft_init_minishell(&minishell);
	ft_minishell_loop(&minishell);
	
	return (0);
}