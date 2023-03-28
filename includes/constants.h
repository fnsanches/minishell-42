/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:01:52 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 21:02:20 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
#define CONSTANTS_H

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

#endif
