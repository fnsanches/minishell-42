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

#define DEFAULT "\001\033[0;39m\002"
#define GRAY "\001\033[1;90m\002"
#define RED "\001\033[1;91m\002"
#define GREEN "\001\033[1;92m\002"
#define YELLOW "\001\033[1;93m\002"
#define BLUE "\001\033[1;94m\002"
#define MAGENTA "\001\033[1;95m\002"
#define CYAN "\001\033[1;96m\002"
#define WHITE "\001\033[0;97m\002"

size_t ft_strlen(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char *str_prompt(void);

char *str_prompt(void)
{
    char *user = getenv("USER");
    // printf("%s", user);
    if (!user)
        user = "guest";
    user = ft_strjoin(user, "@");
    user = ft_strjoin(BLUE, user);
    char *host = getenv("HOST");
    // printf("%s", host);
    if (!host)
        host = "minishell:";
    char *pwd = getenv("PWD");
    // printf("%s", pwd);
    if (!pwd)
        pwd = "$";
    char *prompt = calloc(strlen(user) + strlen(host) + strlen(pwd) + 5, sizeof(char));
    char **arr = calloc(4, sizeof(char *));
    arr[0] = user;
    arr[1] = host;
    arr[2] = pwd;
    arr[3] = NULL;
    while (*arr)
    {
        prompt = ft_strjoin(prompt, *arr);
        arr++;
    }
    prompt = ft_strjoin(prompt, " ");
    prompt = ft_strjoin(prompt, DEFAULT);
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

char *ft_strjoin(char const *s1, char const *s2)
{
    int len_s1;
    int len_s2;
    char *s3;
    int i;

    if (s1 == NULL && s2 == NULL)
        return (NULL);
    i = 0;
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    s3 = (char *)calloc((len_s1 + len_s2 + 1), sizeof(char));
    if (s3 == NULL)
        return (NULL);
    while (i < len_s1 || i < len_s2)
    {
        if (i < len_s1)
            s3[i] = s1[i];
        if (i < len_s2)
            s3[i + len_s1] = s2[i];
        i++;
    }
    s3[len_s1 + len_s2] = '\0';
    return (s3);
}

size_t ft_strlen(const char *s)
{
    int count;

    count = 0;
    if (!s)
        return (count);
    while (*s != '\0')
    {
        count++;
        s++;
    }
    return (count);
}