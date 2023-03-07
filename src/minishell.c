#include "../inc/minishell.h"

int g_status;

int main(int argc, char **argv, char **envp)
{
    if (argc != 1)
        return (throw_error(0, 1, "No arguments in this program"));
    return (minishell(argv, envp));
}

void print_error(char *error)
{
    ft_putstr_fd("\033[0;31m", 2);
    ft_putstr_fd(error, 2);
    ft_putstr_fd("\033[0m", 2);
}

int throw_error(int err_type, int error_code, char *message)
{
    g_status = error_code;
    if (err_type == FORKERR)
        print_error("minishell: fork failed");
    if (err_type == QUOTE)
        print_error("minishell: not found matching quote");
    if (err_type == PIPENDERR)
        print_error("minishell: syntax error near unexpected token `|'");
    if (err_type == OPENFILEERR)
        print_error("minishell: syntax error near unexpected token `newline'");
    if (err_type == NDIR)
        print_error("minishell: No such file or directory: ");
    if (err_type == NPERM)
        print_error("minishell: permission denied: ");
    if (err_type == PIPERR)
        print_error("minishell: error creating pipe");
    if (err_type == IS_DIR)
        print_error("minishell: Is a directory: ");
    if (err_type == NOTFOUNDCMD)
        print_error("minishell: command not found: ");
    if (err_type == DUPERR)
        print_error("minishell: dup2 failed");
    print_error(message);
    ft_putstr_fd("\n", 2);
    return (1);
}

pid_t get_pid(t_data *result)
{
    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        throw_error(FORKERR, 1, NULL);
        exit(1);
    }
    if (pid == 0)
    {
        free_data(result);
        exit(1);
    }
    waitpid(pid, NULL, 0);
    return (pid - 1);
}

void init_vars(t_data *data, char *program_name)
{
    init_pwd(data);
    init_shlvl(data);
    init_path(data);
    init_executable(data, program_name);
}

t_data init_data(char **argv, char **envp)
{
    t_data result;

    result.input = NULL;
    result.cmds = NULL;
    result.running = 1;
    result.envp = dup_matrix(envp);
    result.pid = get_pid(&result);
    g_status = 0;
    init_vars(&result, argv[0]);
    return (result);
}

void input_loop(t_data *data)
{
    char *prompt;
    clear_window();
    while (data->running)
    {
        set_default_signal_handlers();
        prompt = get_prompt(data);
        data->input = readline(prompt);
        if (!handle_input(data))
            data->running = 0;
    }
}

int minishell(char **argv, char **envp)
{
    t_data data;

    data = init_data(argv, envp);
    input_loop(&data);
    free_data(&data);
    return (g_status);
}

void init_pwd(t_data *data)
{
    char *current_dir;

    current_dir = getcwd(NULL, 0);
    data->envp = set_env("PWD", current_dir, data->envp);
    free(current_dir);
}

char *join_env(char *key, char *value)
{
    char *aux1;
    char *aux2;
    char *result;

    aux1 = ft_strdup(key);
    aux2 = ft_strcat(aux1, "=");
    result = ft_strcat(aux2, value);
    free(aux1);
    free(aux2);
    return (result);
}

char **change_env_value(int index, char *key, char *value, char **envp)
{
    char *new_value;
    char **result;

    new_value = join_env(key, value);
    result = matrix_replace(envp, index, new_value);
    free(new_value);
    return (result);
}

char **add_new_env(char *key, char *value, char **envp)
{
    char *variable_joined;
    char **result;

    variable_joined = join_env(key, value);
    result = matrix_push(envp, variable_joined);
    free(variable_joined);
    return (result);
}

char **set_env(char *key, char *value, char **envp)
{
    int env_index;

    env_index = get_env_index(key, envp);
    if (env_index > -1)
        return (envp = change_env_value(env_index, key, value, envp));
    return (envp = add_new_env(key, value, envp));
}

void init_shlvl(t_data *data)
{
    char *current_shlvl;
    char *previous_shlvl;

    previous_shlvl = get_env("SHLVL", data->envp, 5);
    if (!previous_shlvl || ft_atoi(previous_shlvl) <= 0)
        current_shlvl = ft_strdup("1");
    else
        current_shlvl = ft_itoa(ft_atoi(previous_shlvl) + 1);
    data->envp = set_env("SHLVL", current_shlvl, data->envp);
    free(current_shlvl);
    free(previous_shlvl);
}

void init_path(t_data *data)
{
    char *current_path;

    current_path = get_env("PATH", data->envp, 4);
    if (!current_path)
    {
        data->envp = set_env("PATH", DEFAULT_PATH, data->envp);
        return;
    }
    free(current_path);
}

void init_executable(t_data *data, char *program_name)
{
    data->envp = set_env("_", program_name, data->envp);
}

char *get_env(char *key, char **envp, int key_len)
{
    int i;

    i = 0;
    if (key_len < 0)
        key_len = ft_strlen(key);
    while (envp[i])
    {
        if (ft_strncmp(key, envp[i], key_len) == 0 && envp[i][key_len] == '=')
            return (ft_strdup(envp[i] + key_len + 1));
        i++;
    }
    return (NULL);
}

int get_env_index(char *key, char **envp)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(key);
    while (envp[i])
    {
        if (ft_strncmp(key, envp[i], len) == 0 && envp[i][len] == '=')
            return (i);
        i++;
    }
    return (-1);
}

void handle_sigint(int sig)
{
    if (sig == SIGINT)
    {
        g_status = 130;
        ioctl(STDIN_FILENO, TIOCSTI, "\n");
        rl_replace_line("", 0);
        rl_on_new_line();
    }
}

void set_default_signal_handlers(void)
{
    signal(SIGINT, handle_sigint);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
}

void set_child_process_signal_handlers(void)
{
    signal(SIGINT, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    signal(SIGTSTP, SIG_DFL);
}

int handle_input(t_data *data)
{
    int status;

    status = 1;
    if (is_invalid_input(data->input))
        return (get_invalid_input_status(data->input));
    add_history(data->input);
    if (!lexer(data))
        return (throw_error(QUOTE, 1, NULL));
    print_matrix(data->args);
    parse_args(data);
    status = executor(data);
    clean(data);
    return (status);
}

int lexer(t_data *data)
{
    data->args = split_quotes(data->input, " ");
    if (!data->args)
    {
        free(data->input);
        return (0);
    }
    expand_args(data->args, data);
    data->args = subsplit_pipes_and_redirections(data->args);
    return (1);
}

// expand var
int should_var_be_expanded(char *str, int i, int sq_open, int dq_open)
{
    int found_forbidden_char_after_dollar;
    int not_has_dq_case_trated;
    int has_dq_case_trated;

    if (sq_open || str[i] != '$' || !str[i + 1])
        return (0);
    found_forbidden_char_after_dollar = ft_strchars_i(str + i + 1, "/~%^{}:;");
    if (found_forbidden_char_after_dollar == 0)
        return (0);
    not_has_dq_case_trated = (ft_strchars_i(str + i + 1, " ") && !dq_open);
    has_dq_case_trated = (ft_strchars_i(str + i + 1, "\"") && dq_open);
    return (not_has_dq_case_trated || has_dq_case_trated);
}

char *expand_vars(char *str, t_data *data)
{
    int sq_open;
    int dq_open;
    int i;

    sq_open = 0;
    dq_open = 0;
    i = 0;
    while (str && str[i])
    {
        sq_open = (sq_open + (!dq_open && str[i] == SINGLE_QUOTE)) % 2;
        dq_open = (dq_open + (!sq_open && str[i] == DOUBLE_QUOTE)) % 2;
        if (should_var_be_expanded(str, i, sq_open, dq_open))
            return (expand_vars(get_substr_var(str, ++i, data), data));
        i++;
    }
    return (str);
}

int should_path_be_expanded(char *str, int i, int sq_open, int dq_open)
{
    if (sq_open || dq_open)
        return (0);
    if (str[i] != '~')
        return (0);
    if (i != 0 && str[i - 1] == '$')
        return (0);
    return (1);
}

char *expand_path(char *str, t_data *data)
{
    int sq_open;
    int dq_open;
    int i;

    sq_open = 0;
    dq_open = 0;
    i = 0;
    while (str && str[i])
    {
        sq_open = (sq_open + (!dq_open && str[i] == SINGLE_QUOTE)) % 2;
        dq_open = (dq_open + (!sq_open && str[i] == DOUBLE_QUOTE)) % 2;
        if (should_path_be_expanded(str, i, sq_open, dq_open))
            return (expand_path(get_substr_path(str, i, data), data));
        i++;
    }
    return (str);
}

void expand_args(char **args, t_data *data)
{
    int i;

    i = 0;
    while (args[i])
    {
        args[i] = expand_vars(args[i], data);
        args[i] = expand_path(args[i], data);
        i++;
    }
}
