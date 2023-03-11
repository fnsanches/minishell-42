#include "../inc/minishell.h"

int exec_exit(t_cmd *cmd)
{
    ft_putendl_fd("exit", 2);
    if (!cmd->full_cmd || !cmd->full_cmd[1])
    {
        g_status = 0;
        return (0);
    }
    if (cmd->full_cmd[2])
    {
        ft_putendl_fd("minishell: exit: too many arguments", 2);
        return (1);
    }
    g_status = restrict_atoi(cmd->full_cmd[1]);
    if (g_status == -1)
    {
        ft_putstr_fd("minishell: exit: ", 2);
        ft_putstr_fd(cmd->full_cmd[1], 2);
        ft_putstr_fd(": numeric argument required\n", 2);
        g_status = 255;
    }
    g_status %= 256;
    return (0);
}