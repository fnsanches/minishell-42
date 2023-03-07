/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:38:37 by fsanches          #+#    #+#             */
/*   Updated: 2023/02/27 17:38:37 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include "../libft/includes/libft.h"
#include <dirent.h>
#include <fcntl.h>
#include <limits.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <string.h>
#include <sys/errno.h>
#include <sys/ioctl.h>
#include <sys/wait.h>

#define DEFAULT_PATH "/usr/local/sbin:/usr/local/bin:/usr/bin:/bin"
#define HDOC_WARN "minishell: warning: here-document delimited by end-of-file"
#define SINGLE_QUOTE '\''
#define DOUBLE_QUOTE '\"'
#define READ_END 0
#define WRITE_END 1

#define DEFAULT "\001\033[0;39m\002"
#define GRAY "\001\033[1;90m\002"
#define RED "\001\033[1;91m\002"
#define GREEN "\001\033[1;92m\002"
#define YELLOW "\001\033[1;93m\002"
#define BLUE "\001\033[1;94m\002"
#define MAGENTA "\001\033[1;95m\002"
#define CYAN "\001\033[1;96m\002"
#define WHITE "\001\033[0;97m\002"

enum e_error_type
{
    FORKERR = 10,
    QUOTE = 11,
    PIPENDERR = 12,
    OPENFILEERR = 13,
    NDIR = 14,
    NPERM = 15,
    PIPERR = 16,
    IS_DIR = 17,
    NOTFOUNDCMD = 18,
    DUPERR = 19,
};

enum e_redirection_type
{
    REDIRECT_INPUT = 1000,
    REDIRECT_OUTPUT = 1001,
    APPEND_OUTPUT = 1002,
    HEREDOC = 1003,
    PIPE = 1004,
    NORMAL_ARG = 1005,
    NO_ARG = 1404,
};

typedef struct s_data
{
    char *input;
    char **envp;
    int running;
    char **args;
    t_list *cmds;
    pid_t pid;
} t_data;

typedef struct s_cmd
{
    char **full_cmd;
    char *cmd_path;
    int infile;
    int outfile;
} t_cmd;

extern int g_status;

// minishell.c
int minishell(char **argv, char **envp);

// signal.c
void handle_sigint(int sig);
void set_default_signal_handlers(void);
void set_child_process_signal_handlers(void);

// common.c
int throw_error(int err_type, int error_code, char *message);

// free.c
void free_data(t_data *data);
void free_node(void *node);
void clean(t_data *data);

// handle_input.c
int handle_input(t_data *data);
char *get_prompt(t_data *data);

int lexer(t_data *data);
char **split_quotes(char const *s, char *set);
char **subsplit_pipes_and_redirections(char **args);

void expand_args(char **args, t_data *data);
char *expand_vars(char *str, t_data *data);
char *expand_path(char *str, t_data *data);

char *get_substr_var(char *str, int i, t_data *data);
char *get_substr_path(char *str, int i, t_data *data);

char **dup_matrix(char **matrix);
char **matrix_push(char **matrix, char *new);
char **matrix_replace(char **matrix, int i, char *new_value);
char **matrix_remove(char **matrix, int to_remove);
int matrix_len(char **matrix);
void print_matrix(char **matrix);
void free_matrix(char **matrix);

int get_env_index(char *key, char **envp);
char *get_env(char *key, char **envp, int key_len);
char **set_env(char *key, char *value, char **envp);

void init_pwd(t_data *data);
void init_shlvl(t_data *data);
void init_path(t_data *data);
void init_executable(t_data *data, char *program_name);

int is_empty(char *input);
int is_null(char *input);
int is_invalid_input(char *input);
int get_invalid_input_status(char *input);

// parser.c
void parse_args(t_data *data);
void fill_nodes(t_data *data);
char **prepare_args(char **args);
char *trim_arg(char *arg, int sq_open, int dq_open);
int should_be_removed(char *str, int i, int sq_open, int dq_open);
void pop_cmd_node(t_data *data, char **prepped_args);
int should_create_node(t_data *data, int i);
int fill_curr_node(t_cmd *node, char **prepped_args, t_data *data, int i);
int count_items_to_remove(char *str);
int get_arg_type(char **args, int i);
int get_heredoc(char *delimiter);
t_cmd *new_node(void);
void stop_parsing(t_data *data);
int empty_pipe_err(void);
int empty_redirection_err(void);
int set_infile_fd(t_cmd *node, char **args, int i);
int open_file(char *path, int oldfd, int is_write, int is_append);
int set_outfile_fd(t_cmd *node, char **args, int i);
int set_heredoc_fd(t_cmd *node, char **args, int i);
int set_append_outfile_fd(t_cmd *node, char **args, int i);

// executor.c
int executor(t_data *data);
int exec_cmds(t_data *data);
int handle_cmd(t_list *node, t_data *data);
int is_config_builtin(t_cmd *node);
int has_next(t_list *node);
int handle_config_builtin(t_list *node, t_data *data);
int is_exit(t_cmd *cmd);
int exec_exit(t_cmd *cmd);
int is_cd(t_cmd *cmd);
int exec_cd(t_cmd *cmd, t_data *data);
int is_export(t_cmd *cmd);
int exec_export(t_cmd *cmd, t_data *data);
int is_unset(t_cmd *cmd);
int exec_unset(t_cmd *cmd, t_data *data);
int is_env(t_cmd *node);
int exec_env(t_data *data);
int is_echo(t_cmd *node);
int exec_echo(t_cmd *cmd);
int is_pwd(t_cmd *node);
int exec_pwd(void);
void wait_child_exit(t_data *data);
int handle_gen_output(t_list *node, t_data *data);
void handle_cmd_path(t_data *data, t_list *node);
void set_path(t_data *data, t_cmd *cmd);
void handle_set_absolute_path(t_cmd *cmd);
void handle_set_relative_path(t_cmd *cmd, t_data *data);
char *find_command_path(char *cmd, t_data *data);
char *set_absolute_path(t_cmd *cmd);
int is_current_folder_dir(t_cmd *cmd);
int send_absolute_path_to_command(t_cmd *cmd);
int send_relative_path_to_command(t_cmd *cmd);
int is_folder_in_current_directory(t_cmd *cmd);
int no_such_file_or_dir(t_cmd *cmd);
int permission_denied(t_cmd *cmd);
int command_not_found(t_cmd *cmd);
int check_errors(t_cmd *cmd);
int execute_command_in_child_process(t_list *node, t_data *data);
void handle_child_process(t_list *node, t_data *data, int fd[2]);
void handle_execution(t_list *node, t_data *data, int fd[2]);
void execute(t_list *node, t_data *data, int fd[2]);
int can_execute_in_child_process(t_cmd *cmd);
int handle_redirections(t_list *node, int fd[2]);
int is_builtin(t_cmd *node);
int is_config_builtin(t_cmd *node);
int is_generate_output_builtin(t_cmd *node);
void handle_fd(int fd[2], t_list *node);
int handle_generate_output(t_list *node, t_data *data);
int handle_generate_output_builtin(t_list *node, t_data *data);

// helper functions
int ft_strchars_i(const char *s, char *set);
char *ft_strcat(char *src, char *dest); // add to libft
void clear_window(void);
void print_nodes(t_data *data);
int restrict_atoi(const char *str);

#endif