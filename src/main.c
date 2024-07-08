#include "../includes/minishell.h"

t_minishell	g_minishell;

static void		ft_init_minishell(char **env)
{
	ft_memset(&g_minishell, 0, sizeof(t_minishell));
	g_minishell.enviro = env;
	ft_init_envlst();
	g_minishell.stdin = dup(0);
	g_minishell.stdout = dup(1);
	tcgetattr(STDIN_FILENO, &g_minishell.original_term);
}

int main(int argc, char **argv, char **env)
{
	((void)argc, (void)argv);
    ft_init_minishell(env);
	while(1){
    	g_minishell.line = readline(PROMPT);
		if(!g_minishell.line)
			(ft_clean_ms(),
				ft_pustr_fd("exit\n", 1), exit(g_minishell.exit_s));
		if(g_minishell.line[0])
			add_history(g_minishell.line);
		g_minishell.tokens = ft_tokenize();
		if (!g_minishell.tokens)
			continue ;
	}
    return (0);
}
