/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:53:59 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:35 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_command(t_list *node, t_data *data)
{
	t_cmd	*command;

	command = node->content;
	if (!command->full_cmd)
		return (1);
	if (is_config_builtin(command) && !has_next(node))
		return (handle_config_builtin(node, data));
	return (handle_generate_output(node, data));
}

int	execute_commands(t_data *data)
{
	t_list	*current_node;
	int		status;

	current_node = data->cmds;
	status = 1;
	while (current_node)
	{
		status = handle_command(current_node, data);
		current_node = current_node->next;
	}
	wait_child_processes_exit(data);
	return (status);
}

int	executor(t_data *data)
{
	if (!data->cmds)
		return (1);
	return (execute_commands(data));
}
