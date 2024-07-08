#include "../includes/minishell.h"

int main(void)
{
    char *rl;
	while(1){
    	rl = readline("MDshell >");
    	add_history(rl);
		if (rl == NULL)
		{
			clear_history();
			return(0);
		}
    	printf("%s\n", rl);
	}
    return (0);
}
