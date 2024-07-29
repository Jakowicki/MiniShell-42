#include "../../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <string.h>


int main(int ac, char *av[], char **env) {
    int test = 10;
    char *line;
    char *args[3]; // Assuming maximum of 3 arguments for simplicity
    t_content   minishell;
    minishell.envir = env;
    minishell.enviroment = NULL;
    ft_init_env(&minishell);
    while (1) {
        line = readline("TEST ");
        if (!line) {
            break; // Handle end-of-input (EOF) or error
        }

        if (!ft_strncmp(line, "pwd", 3)) {
            test = md_pwd();
        } else if (!ft_strncmp(line, "echo", 4)) {
            test = md_echo(av);
        } else if (!ft_strncmp(line, "cd", 2)) {
            // Parse the command and its arguments
            int i = 0;
            char *token = strtok(line, " ");
            while (token != NULL && i < 3) {
                args[i++] = token;
                token = strtok(NULL, " ");
            }
            args[i] = NULL; // Null-terminate the arguments array

            // Call the cd function with parsed arguments
            test = md_cd(args, &minishell);
        } else if (!ft_strncmp(line, "env", 3)) {
            // Print environment variables
            md_env(&minishell);
        }
        else if (!ft_strncmp(line, "unset", 5))
            md_unset(&minishell.enviroment, &av[2]);

        free(line);
    }

    return 0;
}
