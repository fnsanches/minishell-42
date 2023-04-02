/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caue.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:55:14 by felcaue-          #+#    #+#             */
/*   Updated: 2023/03/29 20:15:14 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAUE_H
# define CAUE_H

# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <errno.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <termcap.h>
# include <sys/ioctl.h>

// import readline
# include <readline/readline.h>
# include <readline/history.h>

// import system call
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// import string
# include <string.h>

// import stdio
# include <stdio.h>

// import stdlib
# include <stdlib.h>

// Colours
# define GREEN "\e[1;32m"
# define RESET "\e[0m"
# define RED "\e[1;91m"
# define CYAN "\e[1;36m"
# define YELLOW "\e[1;33m"
# define PURPLE "\e[1;35m"
# define BLUE "\e[1;34m"

/******* LESXER **********/

typedef enum e_token_type{
	GREAT,
	LESS,
	DOUBLE_GREAT,
}			t_token_type;

typedef struct s_token
{
	int				index;
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}				t_token;

/******* PARSER **********/

typedef enum e_redirection_type{
	RE_GREAT,
	RE_DOUBLE_GREAT,
	RE_LESS,
}			t_redirection_type;

typedef struct s_redirection
{
	int						index;
	t_redirection_type		type;
	int						inside_quotes;
	char					*file_name;
	struct s_redirection	*next;
}				t_redirection;

typedef struct s_args{
	int				inside_quotes;
	char			*value;
	struct s_args	*next;
}				t_args;

typedef struct s_simple_cmd
{
	int					inside_quotes;
	char				*command;
	t_args				*args;
	t_redirection		*redirections;
	struct s_simple_cmd	*next;
}				t_simple_cmd;

typedef struct s_pipe_line
{
	int					simple_cmd_count;
	struct s_pipe_line	*next;
	t_simple_cmd		*child;
}				t_pipe_line;

typedef struct s_command_list
{
	int			pipe_line_count;
	t_pipe_line	*childs;
}				t_command_list;

/***** ENV LIST ******/

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct s_char_list{
	char				value;
	int					len;
	struct s_char_list	*next;
}				t_char_list;

typedef struct s_lines_list{
	char				value;
	int					history;
	int					index;
	bool				up_or_down;
	t_char_list			*char_list;
	t_char_list			*origin_char_list;
	struct s_lines_list	*next;
	struct s_lines_list	*prev;
}				t_lines_list;

typedef struct s_g_vars
{
	t_command_list	*cmd;
	t_lines_list	*history;
	int				infork;
}				t_g_vars;

typedef struct s_expansion
{
	char	*word;
	char	*expanded;
	char	*tmp1;
	char	*tmp;
}				t_expansion;

////////////////////////////////////////////////////////////
/////                GLOBAL     VARIABLE               /////
////////////////////////////////////////////////////////////

t_g_vars	g_vars;

////////////////////////////////////////////////////////////
/////             F  U  N  C  T  I  O  N  S            /////
////////////////////////////////////////////////////////////

// Handle_env

void		work_minishell(char **env);
void		init_minishell(char	**exit_status, char **line,
				t_pipe_line **current_pl, t_env **envs_list);
void		init_env(t_env **head, char **env);
void		destroy_envs(t_env *head);

// Envs_01

t_env		*create_node(char *name, char *value);
void		add_to_list(t_env **head, t_env *newnode);

// Envs_utils

char		*int_to_str(int number);
static int	int_len(unsigned int number);
int			execute_pl(t_pipe_line *cur_pl, char **la_exit,
				int *status, t_env **envs_list);
void		expand(t_pipe_line *pl, t_env **envs, char **l_env);

// Env_splitter

char		**splitter(char *str);
void		aftr_equal(char *string, char **str, int id);
static int	characters(char *string, char chr);

#endif
