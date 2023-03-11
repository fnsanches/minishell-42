#include "../inc/minishell.h"

int exec_pwd(void)
{
    char *cwd;

    cwd = getcwd(NULL, 0);
    printf("%s\n", cwd);
    free(cwd);
    return (1);
}