/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Envs_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felcaue- <felcaue-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:44:17 by felcaue-          #+#    #+#             */
/*   Updated: 2023/03/29 20:18:07 by felcaue-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "caue.h"

t_env	*create_node(char *name, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (node)
	{
		node->name = ft_strdup(name);
		node->value = ft_strdup(value);
		node->next = NULL;
	}
	return (node);
}

void	add_to_list(t_env **head, t_env *newnode)
{
	t_env	*list;

	if (!head || !newnode)
		return ;
	if (*head)
	{
		list = *head;
		while (list && list->next)
			list = list->next;
		list->next = newnode;
	}
	else
		*head = newnode;
}

int	execute_pl(t_pipe_line *cur_pl, char **la_exit,
			int *status, t_env **envs_list)
{
	if (la_exit[0])
		free(la_exit[0]);
	la_exit[0] = int_to_str(*status);
	expand(cur_pl, envs_list, la_exit);
	cur_pl->child = ft_delete_emty_simple_cmds(&cur_pl);
	if (cur_pl->child)
	{
		if (la_exit[1])
			free(la_exit[1]);
		la_exit[1] = get_last_argument_or_command(cur_pl);
		*status = ft_execute(cur_pl, envs_list);
	}
	return (*status);
}

void	expand(t_pipe_line *pl, t_env **envs, char **l_env)
{
	t_simple_cmd	*current;
	t_simple_cmd	*head;

	current = NULL;
	head = NULL;
	ft_putstr_fd(RED, 1);
	head = pl->child;
	while (head)
	{
		current = head;
		expand_cmd(&current, envs, l_env);
		head = head->next;
	}
}
