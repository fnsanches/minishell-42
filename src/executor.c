#include "../inc/minishell.h"

int executor(t_data *data)
{
    if (!data->cmds)
        return (1);
    return (exec_cmds(data));
}

int exec_cmds(t_data *data)
{
    t_list *curr_node = data->cmds;
    int status = 1;
    while (curr_node)
    {
        status = handle_cmd(curr_node, data);
        curr_node = curr_node->next;
    }
    wait_child_exit(data);
    return (status);
}

int handle_cmd(t_list *node, t_data *data)
{
    t_cmd *cmd = node->content;
    if (!cmd->full_cmd)
        return (1);
    if (is_config_builtin(cmd) && !has_next(node))
        return (handle_config_builtin(node, data));
    return (handle_gen_output(node, data));
}

int has_next(t_list *node)
{
    return (node->next != NULL);
}

int handle_config_builtin(t_list *node, t_data *data)
{
    t_cmd *cmd = node->content;
    if (is_exit(cmd))
        return (exec_exit(cmd));
    if (is_cd(cmd))
        return (exec_cd(cmd, data));
    if (is_export(cmd))
        return (exec_export(cmd, data));
    if (is_unset(cmd))
        return (exec_unset(cmd, data));
    return (1);
}

// exit
int is_exit(t_cmd *command)
{
    char *cmd = command->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
        return (1);
    return (0);
}

// cd
int is_cd(t_cmd *command)
{
    char *cmd = command->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 2)
        return (1);
    return (0);
}

// export
int is_export(t_cmd *command)
{
    char *cmd = command->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 6)
        return (1);
    return (0);
}

int exec_export(t_cmd *cmd, t_data *data)
{
    ft_putendl_fd("exit - export", 2);
    return (0);
}
// unset
int is_unset(t_cmd *command)
{
    char *cmd = command->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 5)
        return (1);
    return (0);
}

int exec_unset(t_cmd *cmd, t_data *data)
{
    ft_putendl_fd("exit - unset", 2);
    return (0);
}
// env
int is_env(t_cmd *node)
{
    char *cmd;

    cmd = node->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
        return (1);
    return (0);
}

int exec_env(t_data *data)
{
    ft_putendl_fd("exit - env", 2);
    print_matrix(data->envp);
    return (0);
}
// echo
int is_echo(t_cmd *node)
{
    char *cmd;

    cmd = node->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
        return (1);
    return (0);
}

// pwd
int is_pwd(t_cmd *node)
{
    char *cmd;

    cmd = node->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
        return (1);
    return (0);
}

void wait_child_exit(t_data *data)
{
    int i;

    i = 0;
    while (i < ft_lstsize(data->cmds))
    {
        waitpid(-1, &g_status, 0);
        i++;
    }
}

int handle_gen_output(t_list *node, t_data *data)
{
    int fd[2];
    handle_cmd_path(data, node);
    if (pipe(fd) == -1)
        return (throw_error(PIPERR, 1, NULL));
    execute(node, data, fd);
    handle_fd(fd, node);
    return (1);
}

void handle_cmd_path(t_data *data, t_list *node)
{
    t_cmd *cmd = node->content;
    set_path(data, cmd);
    check_errors(cmd);
}

void set_path(t_data *data, t_cmd *cmd)
{
    if (is_current_folder_dir(cmd))
        return;
    if (send_absolute_path_to_command(cmd))
        return (handle_set_absolute_path(cmd));
    if (send_relative_path_to_command(cmd))
        return (handle_set_relative_path(cmd, data));
}

void handle_set_absolute_path(t_cmd *cmd)
{
    cmd->cmd_path = set_absolute_path(cmd);
}

void handle_set_relative_path(t_cmd *cmd, t_data *data)
{
    cmd->cmd_path = find_command_path(*cmd->full_cmd, data);
}

char *find_command_path(char *cmd, t_data *data)
{
    char *temp;
    char *result;
    char **env_split;
    int i;

    temp = get_env("PATH", data->envp, 4);
    env_split = ft_split(temp, ':');
    free(temp);
    i = -1;
    result = NULL;
    while (env_split && env_split[++i])
    {
        free(result);
        temp = ft_strjoin(env_split[i], "/");
        result = ft_strjoin(temp, cmd);
        free(temp);
        if (access(result, F_OK) == 0)
        {
            free_matrix(env_split);
            return (result);
        }
    }
    free(result);
    free_matrix(env_split);
    return (NULL);
}

char *set_absolute_path(t_cmd *cmd)
{
    char *result;
    char **s;

    s = ft_split(*cmd->full_cmd, '/');
    result = ft_strdup(*cmd->full_cmd);
    free(cmd->full_cmd[0]);
    cmd->full_cmd[0] = ft_strdup(s[matrix_len(s) - 1]);
    free_matrix(s);
    return (result);
}

int is_current_folder_dir(t_cmd *cmd)
{
    DIR *dir;

    dir = NULL;
    if (!cmd || !cmd->full_cmd)
        return (0);
    dir = opendir(cmd->full_cmd[0]);
    if (!dir)
        return (0);
    closedir(dir);
    return (1);
}

int send_absolute_path_to_command(t_cmd *cmd)
{
    return (cmd && cmd->full_cmd && ft_strchr(*cmd->full_cmd, '/'));
}

int send_relative_path_to_command(t_cmd *cmd)
{
    return (!is_builtin(cmd) && cmd && cmd->full_cmd);
}

int is_folder_in_current_directory(t_cmd *cmd)
{
    if (is_builtin(cmd))
        return (0);
    return (is_current_folder_dir(cmd));
}

int no_such_file_or_dir(t_cmd *cmd)
{
    if (is_builtin(cmd))
        return (0);
    return (cmd && cmd->cmd_path && access(cmd->cmd_path, F_OK) == -1);
}

int permission_denied(t_cmd *cmd)
{
    if (is_builtin(cmd))
        return (0);
    return (cmd && cmd->cmd_path && access(cmd->cmd_path, X_OK) == -1);
}

int command_not_found(t_cmd *cmd)
{
    if (is_builtin(cmd))
        return (0);
    return (!cmd->cmd_path || !cmd->full_cmd[0] || !cmd->full_cmd[0][0]);
}

int check_errors(t_cmd *cmd)
{
    if (is_folder_in_current_directory(cmd))
        return (throw_error(IS_DIR, 126, *cmd->full_cmd));
    if (no_such_file_or_dir(cmd))
        return (throw_error(NDIR, 127, cmd->cmd_path));
    if (permission_denied(cmd))
        return (throw_error(NPERM, 126, cmd->cmd_path));
    if (command_not_found(cmd))
        return (throw_error(NOTFOUNDCMD, 127, *cmd->full_cmd));
    return (0);
}

int execute_command_in_child_process(t_list *node, t_data *data)
{
    t_cmd *cmd;

    cmd = node->content;
    set_child_process_signal_handlers();
    if (is_generate_output_builtin(cmd))
        return (handle_generate_output_builtin(node, data));
    execve(cmd->cmd_path, cmd->full_cmd, data->envp);
    return (1);
}

void handle_child_process(t_list *node, t_data *data, int fd[2])
{
    handle_redirections(node, fd);
    close(fd[READ_END]);
    execute_command_in_child_process(node, data);
    ft_lstclear(&data->cmds, free_node);
    free_matrix(data->args);
    free_matrix(data->envp);
    exit(g_status);
}

void handle_execution(t_list *node, t_data *data, int fd[2])
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        close(fd[READ_END]);
        close(fd[WRITE_END]);
        throw_error(FORKERR, 1, NULL);
    }
    if (pid == 0)
    {
        handle_child_process(node, data, fd);
    }
}

void execute(t_list *node, t_data *data, int fd[2])
{
    t_cmd *cmd;

    cmd = node->content;
    if (cmd->infile == -1 || cmd->outfile == -1)
        return;
    if (can_execute_in_child_process(cmd))
        handle_execution(node, data, fd);
}

int can_execute_in_child_process(t_cmd *cmd)
{
    if (is_builtin(cmd))
        return (1);
    return (cmd->cmd_path && access(cmd->cmd_path, X_OK) == 0);
}

int handle_redirections(t_list *node, int fd[2])
{
    t_cmd *cmd;

    cmd = node->content;
    if (cmd->infile != STDIN_FILENO)
    {
        if (dup2(cmd->infile, STDIN_FILENO) == -1)
            return (throw_error(DUPERR, 1, NULL));
        close(cmd->infile);
    }
    if (cmd->outfile != STDOUT_FILENO)
    {
        if (dup2(cmd->outfile, STDOUT_FILENO) == -1)
            return (throw_error(DUPERR, 1, NULL));
        close(cmd->outfile);
    }
    if (node->next && cmd->outfile == STDOUT_FILENO)
    {
        if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
            return (throw_error(DUPERR, 1, NULL));
        close(fd[WRITE_END]);
    }
    return (1);
}

int is_builtin(t_cmd *node)
{
    char *cmd;

    cmd = node->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strchr(cmd, '/'))
        return (0);
    if (node->cmd_path && ft_strchr(node->cmd_path, '/'))
        return (0);
    if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
        return (1);
    if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
        return (1);
    if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 2)
        return (1);
    if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 6)
        return (1);
    if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 5)
        return (1);
    if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
        return (1);
    if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
        return (1);
    return (0);
}

int is_config_builtin(t_cmd *node)
{
    char *cmd;

    cmd = node->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strchr(cmd, '/'))
        return (0);
    if (node->cmd_path && ft_strchr(node->cmd_path, '/'))
        return (0);
    if (ft_strncmp(cmd, "cd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 2)
        return (1);
    if (ft_strncmp(cmd, "export", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 6)
        return (1);
    if (ft_strncmp(cmd, "unset", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 5)
        return (1);
    if (ft_strncmp(cmd, "exit", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
        return (1);
    return (0);
}

int is_generate_output_builtin(t_cmd *node)
{
    char *cmd;

    cmd = node->full_cmd[0];
    if (!cmd)
        return (0);
    if (ft_strchr(cmd, '/'))
        return (0);
    if (node->cmd_path && ft_strchr(node->cmd_path, '/'))
        return (0);
    if (ft_strncmp(cmd, "pwd", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
        return (1);
    if (ft_strncmp(cmd, "env", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 3)
        return (1);
    if (ft_strncmp(cmd, "echo", ft_strlen(cmd)) == 0 && ft_strlen(cmd) == 4)
        return (1);
    return (0);
}

void handle_fd(int fd[2], t_list *node)
{
    t_cmd *command;
    t_cmd *next_command;
    t_list *next_node;

    command = node->content;
    next_node = node->next;
    close(fd[WRITE_END]);
    if (next_node)
    {
        next_command = next_node->content;
        if (next_command->infile == STDIN_FILENO)
            next_command->infile = fd[READ_END];
    }
    else
        close(fd[READ_END]);
    if (command->infile > 2)
        close(command->infile);
    if (command->outfile > 2)
        close(command->outfile);
}

int handle_generate_output(t_list *node, t_data *data)
{
    int fd[2];

    handle_cmd_path(data, node);
    if (pipe(fd) == -1)
        return (throw_error(PIPERR, 1, NULL));
    execute(node, data, fd);
    handle_fd(fd, node);
    return (1);
}

int handle_generate_output_builtin(t_list *node, t_data *data)
{
    t_cmd *command;

    command = node->content;
    if (is_env(command))
        exec_env(data);
    if (is_echo(command))
        exec_echo(command);
    if (is_pwd(command))
        exec_pwd();
    return (1);
}