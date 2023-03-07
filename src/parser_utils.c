#include "../inc/minishell.h"

t_cmd *new_node(void)
{
    t_cmd *node;
    node = malloc(sizeof(t_cmd));
    if (!node)
        return (NULL);
    node->full_cmd = NULL;
    node->cmd_path = NULL;
    node->infile = STDIN_FILENO;
    node->outfile = STDOUT_FILENO;
    return (node);
}

int get_arg_type(char **args, int i)
{
    int curr_arg;
    int has_next_arg;
    int next_arg;

    if (!args[i])
        return (NO_ARG);
    curr_arg = args[i][0];
    has_next_arg = args[i + 1] != NULL;
    if (has_next_arg)
        next_arg = args[i + 1][0];
    if (curr_arg == '>' && has_next_arg && next_arg == '>')
        return (APPEND_OUTPUT);
    if (curr_arg == '<' && has_next_arg && next_arg == '<')
        return (HEREDOC);
    if (curr_arg == '>')
        return (REDIRECT_OUTPUT);
    if (curr_arg == '<')
        return (REDIRECT_INPUT);
    if (curr_arg == '|')
        return (PIPE);
    return (NORMAL_ARG);
}

void stop_parsing(t_data *data)
{
    ft_lstclear(&data->cmds, free_node);
}

int empty_pipe_err(void)
{
    throw_error(PIPENDERR, 2, NULL);
    return (-1);
}

int empty_redirection_err(void)
{
    throw_error(OPENFILEERR, 2, NULL);
    return (-1);
}

int open_file(char *path, int oldfd, int is_write, int is_append)
{
    int fd;

    if (oldfd > 2)
        close(oldfd);
    if (!path)
        return (-1);
    if (access(path, F_OK) == -1 && !is_write)
        throw_error(NDIR, 127, path);
    else if (!is_write && access(path, R_OK) == -1)
        throw_error(NPERM, 126, path);
    else if (is_write && access(path, W_OK) == -1 && access(path, F_OK) == 0)
        throw_error(NPERM, 126, path);
    if (is_write && is_append)
        fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0666);
    else if (is_write && !is_append)
        fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    else if (!is_write && oldfd != -1)
        fd = open(path, O_RDONLY);
    else
        fd = oldfd;
    return (fd);
}

int set_infile_fd(t_cmd *node, char **args, int i)
{
    int file_position;

    file_position = i + 1;
    if (!args[file_position])
        return (empty_redirection_err());
    node->infile = open_file(args[file_position], node->infile, 0, 0);
    if (node->infile == -1)
    {
        g_status = 1;
        return (-1);
    }
    return (2);
}

int set_heredoc_fd(t_cmd *node, char **args, int i)
{
    int delimiter_position;

    delimiter_position = i + 2;
    if (!args[delimiter_position])
        return (empty_redirection_err());
    node->infile = get_heredoc(args[delimiter_position]);
    if (node->infile == -1)
    {
        g_status = 1;
        return (-1);
    }
    return (3);
}

int set_outfile_fd(t_cmd *node, char **args, int i)
{
    int file_position;

    file_position = i + 1;
    if (!args[file_position])
        return (empty_redirection_err());
    node->outfile = open_file(args[file_position], node->outfile, 1, 0);
    if (node->outfile == -1)
    {
        g_status = 1;
        return (-1);
    }
    return (2);
}

int set_append_outfile_fd(t_cmd *node, char **args, int i)
{
    int file_position;

    file_position = i + 2;
    if (!args[file_position])
        return (empty_redirection_err());
    node->outfile = open_file(args[file_position], node->outfile, 1, 1);
    if (node->outfile == -1)
    {
        g_status = 1;
        return (-1);
    }
    return (3);
}

/// heredoc

int input_is_delimiter_or_user_quit(char *input, char *delimiter)
{
    int is_delimiter;
    int input_len_eq_delimiter_len;
    size_t input_len;

    if (!input)
        return (0);
    input_len = ft_strlen(input) - 1;
    is_delimiter = (ft_strncmp(input, delimiter, ft_strlen(delimiter)) == 0);
    input_len_eq_delimiter_len = (input_len == ft_strlen(delimiter));
    if (is_delimiter && input_len_eq_delimiter_len)
        return (1);
    if (g_status == 130)
        return (1);
    return (0);
}

char *get_string(char *delimiter)
{
    char *result;
    char *input;
    char *tmp;

    result = NULL;
    input = NULL;
    while (!input_is_delimiter_or_user_quit(input, delimiter))
    {
        tmp = result;
        result = ft_strjoin(result, input);
        free(tmp);
        free(input);
        input = readline("➜ ");
        if (!input)
        {
            printf("%s (wanted `%s\')\n", HDOC_WARN, delimiter);
            break;
        }
        tmp = input;
        input = ft_strjoin(input, "\n");
        free(tmp);
    }
    free(input);
    return (result);
}

int get_heredoc(char *delimiter)
{
    int fd[2];
    char *input_str;

    input_str = NULL;
    g_status = 0;
    if (pipe(fd) == -1)
    {
        throw_error(PIPERR, 1, NULL);
        return (-1);
    }
    input_str = get_string(delimiter);
    write(fd[WRITE_END], input_str, ft_strlen(input_str));
    free(input_str);
    close(fd[WRITE_END]);
    if (g_status == 130)
    {
        close(fd[READ_END]);
        return (-1);
    }
    return (fd[READ_END]);
}