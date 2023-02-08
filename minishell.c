// import readline
#include <readline/readline.h>
#include <readline/history.h>

// import system call
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// import string
#include <string.h>

// import stdio
#include <stdio.h>

// import stdlib
#include <stdlib.h>

char *str_prompt(void)
{
    char *prompt;
    char *base = "minishell : ";
    char *user = getenv("USER");

    prompt = malloc(1024);
    prompt = strcat(prompt, base);
    prompt = strcat(prompt, user);
    printf("%s", prompt);
    return prompt;
}

int main()
{
    char *line;
    char *args[10];
    int status;
    pid_t pid;
    char *prompt;

    while (1)
    {
        prompt = str_prompt();
        line = readline(prompt);
        free(prompt);
        add_history(line);
        if (strcmp(line, "exit") == 0)
            break;
        char *token = strtok(line, " ");
        int i = 0;
        while (token != NULL)
        {
            args[i] = token;
            token = strtok(NULL, " ");
            i++;
        }
        args[i] = NULL;
        pid = fork();
        if (pid == 0)
        {
            execvp(args[0], args);
            exit(0);
        }
        else
            waitpid(pid, &status, 0);
    }
    return 0;
}