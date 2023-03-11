#include "../inc/minishell.h"

static void join_args(int argn, va_list argl, char **result);

static char *get_home(t_data *data)
{
    int i;
    char *home;

    i = 0;
    while (data->envp[i])
    {
        if (ft_strncmp(data->envp[i], "HOME=", 5) == 0)
        {
            home = ft_strdup(data->envp[i] + 5);
            return (home);
        }
        i++;
    }
    return (NULL);
}

static char *get_currwd(t_data *data)
{
    char *currwd;
    char *home;
    int i;

    currwd = getcwd(NULL, 0);
    home = get_home(data);
    if (home && ft_strncmp(currwd, home, ft_strlen(home)) == 0)
    {
        i = ft_strlen(home);
        currwd = ft_strjoin("~", currwd + i);
    }
    free(home);
    return (currwd);
}

static char *get_user(t_data *data)
{
    int i;
    char *user;

    i = 0;
    while (data->envp[i])
    {
        if (ft_strncmp(data->envp[i], "USER=", 5) == 0)
        {
            user = ft_strdup(data->envp[i] + 5);
            return (user);
        }
        i++;
    }
    return (NULL);
}

char *get_prompt(t_data *data)
{
    char *currwd;
    char *user;
    char *prompt;

    currwd = get_currwd(data);
    if (!currwd)
        currwd = ft_strdup("");
    user = get_user(data);
    if (!user)
        user = ft_strdup("guest");
    prompt = ft_strnjoin(8, YELLOW, user, ": ", BLUE, "[", currwd, "] $> ", DEFAULT);
    free(currwd);
    free(user);
    return (prompt);
}

char *ft_strnjoin(int argn, ...)
{
    char *result;
    va_list argl;

    if (argn == 0)
        return (NULL);
    va_start(argl, argn);
    result = NULL;
    join_args(argn, argl, &result);
    va_end(argl);
    return (result);
}

static void join_args(int argn, va_list argl, char **result)
{
    char *buf;
    char *tmp;
    int i;

    i = -1;
    while (++i < argn)
    {
        buf = va_arg(argl, char *);
        if (i == 0)
            *result = ft_strdup(buf);
        else
        {
            tmp = ft_strjoin(*result, buf);
            if (*result)
                free(*result);
            *result = tmp;
        }
    }
}