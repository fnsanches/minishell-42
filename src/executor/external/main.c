/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:54:08 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:35 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void handle_file_descriptors(int fd[2], t_list *node)
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
	handle_file_descriptors(fd, node);
	return (1);
}
