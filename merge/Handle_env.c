/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Handle_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 23:49:28 by felcaue-          #+#    #+#             */
/*   Updated: 2023/03/29 00:01:40 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caue.h"

void	work_minishell(char **env)
{
	t_pipe_line	*current_pl;
	t_env		*envs_list;
	char		*line;
	int			status;
	static char	*exit_status[2];

	status = 0;
	init_minishell(exit_status, &line, &current_pl, &envs_list);
	init_env(&envs_list, env);
	while (1337)
	{
		while (current_pl)
		{
			status = execute_pl(current_pl, exit_status, &status, &envs_list);
			current_pl = current_pl->next;
		}
	}
	destroy_envs(envs_list);
}

void	init_minishell(char	**exit_status, char **line,
			t_pipe_line **current_pl, t_env **envs_list)
{
	g_vars.cmd = NULL;
	*current_pl = NULL;
	exit_status[0] = ft_strdup("0");
	*line = NULL;
	*envs_list = NULL;
}

void	init_env(t_env **head, char **env)
{
	t_env	*env_node;
	char	**var;
	int		counter;

	env_node = NULL;
	counter = 0;
	while (env[counter])
	{
		var = splitter(env[counter]);
		env_node = create_node(var[0], var[1]);
		if (!head)
			head = &env_node;
		else
			add_to_list(head, env_node);
		free(var[0]);
		free(var[1]);
		free(var);
		counter++;
	}
}

void	destroy_envs(t_env *head)
{
	t_env	*temporary;
	t_env	*auxs;

	temporary = head;
	if (head == NULL)
		return ;
	while (temporary != NULL)
	{
		free(temporary->name);
		free(temporary->value);
		auxs = temporary->next;
		free(temporary);
		temporary = auxs;
	}
}
