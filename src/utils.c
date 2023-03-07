#include "../inc/minishell.h"

char **dup_matrix(char **matrix)
{
    char **result;
    int i;

    i = 0;
    result = malloc(sizeof(char *) * (matrix_len(matrix) + 1));
    if (!result)
        return (NULL);
    while (matrix && matrix[i])
    {
        result[i] = ft_strdup(matrix[i]);
        if (!result[i])
        {
            free_matrix(result);
            return (NULL);
        }
        i++;
    }
    result[i] = NULL;
    return (result);
}

void free_data(t_data *data)
{
    free_matrix(data->envp);
}

void free_node(void *node)
{
    t_cmd *cmd;

    cmd = node;
    free_matrix(cmd->full_cmd);
    free(cmd->cmd_path);
    if (cmd->infile != STDIN_FILENO)
        close(cmd->infile);
    if (cmd->outfile != STDOUT_FILENO)
        close(cmd->outfile);
    free(cmd);
}

void clean(t_data *data)
{
    if (data && data->args)
        free_matrix(data->args);
    if (data && data->cmds)
        free(data->input);
    if (data && data->cmds)
        ft_lstclear(&data->cmds, free_node);
}

void free_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix && matrix[i])
    {
        free(matrix[i]);
        i++;
    }
    if (matrix)
        free(matrix);
}

int matrix_len(char **matrix)
{
    int i;

    i = 0;
    while (matrix && matrix[i])
        i++;
    return (i);
}

char **matrix_replace(char **matrix, int i, char *new_value)
{
    if (!matrix || !matrix[i])
        return (NULL);
    free(matrix[i]);
    matrix[i] = ft_strdup(new_value);
    return (matrix);
}

char **matrix_push(char **matrix, char *new)
{
    char **result;
    int i;
    int len;

    i = 0;
    if (!new)
        return (matrix);
    len = matrix_len(matrix);
    result = malloc(sizeof(char *) * (len + 2));
    result[len + 1] = NULL;
    if (!result)
        return (matrix);
    while (i < len)
    {
        result[i] = ft_strdup(matrix[i]);
        if (!result[i])
        {
            free_matrix(matrix);
            free_matrix(result);
        }
        i++;
    }
    result[i] = ft_strdup(new);
    free_matrix(matrix);
    return (result);
}

char **matrix_remove(char **matrix, int to_remove)
{
    char **result;
    int i;
    int j;
    int len;

    if (!matrix || !matrix[to_remove])
        return (matrix);
    i = 0;
    j = 0;
    len = matrix_len(matrix);
    result = malloc(sizeof(char *) * (len));
    result[len] = NULL;
    if (!result)
        return (matrix);
    while (i < len)
    {
        if (i != to_remove)
            result[j++] = ft_strdup(matrix[i]);
        i++;
    }
    free_matrix(matrix);
    return (result);
}

void print_matrix(char **matrix)
{
    int i;

    i = 0;
    while (matrix && matrix[i])
    {
        printf("%s\n", matrix[i]);
        i++;
    }
}

int ft_strchars_i(const char *s, char *set)
{
    int i;

    i = 0;
    if (!s)
        return (-1);
    while (s[i] != '\0')
    {
        if (ft_strchr(set, s[i]))
            return (i);
        i++;
    }
    return (-1);
}

static int is_space(char c)
{
    return (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' || c == ' ');
}

int restrict_atoi(const char *str)
{
    int sign;
    long result;
    size_t i;

    result = 0;
    sign = 1;
    i = 0;
    while (str[i] != '\0' && is_space(str[i]))
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (!ft_isdigit(str[i]))
        return (-1);
    while (str[i] != '\0' && ft_isdigit(str[i]))
    {
        result = (str[i] - '0') + (result * 10);
        i++;
    }
    if (str[i] && !is_space(str[i]))
        return (-1);
    return (result * sign);
}

void print_nodes(t_data *data)
{
    int i;
    t_cmd *curr;
    t_list *curr_node;

    i = 1;
    curr_node = data->cmds;
    while (curr_node)
    {
        curr = curr_node->content;
        printf("------- Node %d -------\n", i);
        printf("full_cmd:\n");
        print_matrix(curr->full_cmd);
        printf("infile => %d\n", curr->infile);
        printf("outfile => %d\n", curr->outfile);
        printf("-----------------------\n\n");
        curr_node = curr_node->next;
        i++;
    }
}

char *ft_strcat(char *src, char *dest)
{
    int i;
    int y;
    int len;
    char *result;

    i = 0;
    y = 0;
    len = (ft_strlen(src) + ft_strlen(dest));
    result = malloc(sizeof(char) * len + 1);
    while (src[i] != '\0')
    {
        result[i] = src[i];
        i++;
    }
    while (dest[y] != '\0')
    {
        result[i] = dest[y];
        i++;
        y++;
    }
    result[i] = '\0';
    return (result);
}

void clear_window(void)
{
    printf("\e[1;1H\e[2J");
}

// handleinput coisas
int is_empty(char *input)
{
    return (input && ft_strlen(input) == 0);
}

int is_null(char *input)
{
    return (input == NULL);
}

int get_invalid_input_status(char *input)
{
    if (is_null(input))
        return (0);
    return (1);
}

int is_invalid_input(char *input)
{
    return (is_empty(input) || is_null(input));
}