#include "../inc/minishell.h"

void parse_args(t_data *data)
{
    if (!data->args)
        return;
    fill_nodes(data);
}

void fill_nodes(t_data *data)
{
    char **prepared_args;
    prepared_args = prepare_args(data->args);
    pop_cmd_node(data, prepared_args);
    free_matrix(prepared_args);
}

char **prepare_args(char **args)
{
    char **res;
    char *trimmed_arg;
    int i = 0;
    res = dup_matrix(args);
    while (res && res[i])
    {
        trimmed_arg = trim_arg(res[i], 0, 0);
        free(res[i]);
        res[i] = trimmed_arg;
        i++;
    }
    return (res);
}

char *trim_arg(char *arg, int sq_open, int dq_open)
{
    char *res;
    int i = 0;
    int j = 0;
    int to_remove = count_items_to_remove(arg);
    res = malloc(sizeof(char) * (ft_strlen(arg) - to_remove + 1));
    while (arg[i])
    {
        sq_open = (sq_open + (!dq_open && arg[i] == SINGLE_QUOTE)) % 2;
        dq_open = (dq_open + (!sq_open && arg[i] == DOUBLE_QUOTE)) % 2;
        if (!should_be_removed(arg, i, sq_open, dq_open))
            res[j++] = arg[i];
        i++;
    }
    res[j] = '\0';
    return (res);
}

int count_items_to_remove(char *str)
{
    int res = 0;
    int sq_open = 0;
    int dq_open = 0;
    int i = 0;
    while (str && str[i])
    {
        sq_open = (sq_open + (!dq_open && str[i] == SINGLE_QUOTE)) % 2;
        dq_open = (dq_open + (!sq_open && str[i] == DOUBLE_QUOTE)) % 2;
        if (should_be_removed(str, i, sq_open, dq_open))
            res++;
        i++;
    }
    return (res);
}

int should_be_removed(char *str, int i, int sq_open, int dq_open)
{
    if (str[i] == DOUBLE_QUOTE && !sq_open)
        return (1);
    if (str[i] == SINGLE_QUOTE && !dq_open)
        return (1);
    return (0);
}

void pop_cmd_node(t_data *data, char **prepped_args)
{
    t_list *curr_node;
    int offset = 0;
    int i = 0;
    while (data->args && data->args[i])
    {
        if (should_create_node(data, i))
        {
            i += data->args[i][0] == '|';
            ft_lstadd_back(&data->cmds, ft_lstnew(new_node()));
        }
        curr_node = ft_lstlast(data->cmds);
        offset = fill_curr_node(curr_node->content, prepped_args, data, i);
        if (offset < 0)
            return (stop_parsing(data));
        i += offset;
    }
}

int should_create_node(t_data *data, int i)
{
    int is_pipe = data->args[i][0] == '|';
    int has_args_after_pipe = (data->args[i + 1] && data->args[i + 1][0] != '|');
    if (i == 0)
        return (1);
    if (is_pipe && has_args_after_pipe)
        return (1);
    return (0);
}

int fill_curr_node(t_cmd *node, char **prepped_args, t_data *data, int i)
{
    int arg_type = get_arg_type(data->args, i);
    if (arg_type == PIPE || arg_type == NO_ARG)
        return (empty_pipe_err());
    if (arg_type == APPEND_OUTPUT)
        return (set_append_outfile_fd(node, prepped_args, i));
    if (arg_type == HEREDOC)
        return (set_heredoc_fd(node, prepped_args, i));
    if (arg_type == REDIRECT_OUTPUT)
        return (set_outfile_fd(node, prepped_args, i));
    if (arg_type == REDIRECT_INPUT)
        return (set_infile_fd(node, prepped_args, i));
    if (arg_type == NORMAL_ARG)
        node->full_cmd = matrix_push(node->full_cmd, prepped_args[i]);
    return (1);
}
