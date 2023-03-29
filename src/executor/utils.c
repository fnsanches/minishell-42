/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:53:54 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:35 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	has_next(t_list *node)
{
	return (node->next != NULL);
}

void	wait_child_processes_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < ft_lstsize(data->cmds))
	{
		waitpid(-1, &g_status, 0);
		i++;
	}
}
