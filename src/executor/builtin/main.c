/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:55:00 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:34 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	handle_config_builtin(t_list *node, t_data *data)
{
	t_cmd	*command;

	command = node->content;
	if (is_exit(command))
		return (execute_exit(command));
	if (is_cd(command))
		return (execute_cd(command, data));
	if (is_unset(command))
		return (execute_unset(command, data));
	if (is_export(command))
		return (execute_export(command, data));
	return (1);
}

int	handle_generate_output_builtin(t_list *node, t_data *data)
{
	t_cmd	*command;

	command = node->content;
	if (is_env(command))
		execute_env(data);
	if (is_echo(command))
		execute_echo(command);
	if (is_pwd(command))
		execute_pwd();
	return (1);
}
