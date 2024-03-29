/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:54:32 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:34 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

int	can_execute_in_child_process(t_cmd *cmd)
{
	if (is_builtin(cmd))
		return (1);
	return (cmd->cmd_path && access(cmd->cmd_path, X_OK) == 0);
}

int	handle_redirections(t_list *node, int fd[2])
{
	t_cmd	*cmd;

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
