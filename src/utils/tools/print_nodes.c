/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:51:15 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:39 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	print_nodes(t_data *data)
{
	int		i;
	t_cmd	*curr;
	t_list	*curr_node;

	i = 1;
	curr_node = data->cmds;
	while (curr_node)
	{
		curr = curr_node->content;
		printf("------- Node %d -------\n", i);
		printf("full_cmd:\n");
		print_matrix(curr->full_cmd);
		printf("infile => %d\n", curr->infile);
		printf("outfile => %d\n", curr->outfile);
		printf("-----------------------\n\n");
		curr_node = curr_node->next;
		i++;
	}
}
