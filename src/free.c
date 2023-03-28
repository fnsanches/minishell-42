/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:50:17 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:39 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
