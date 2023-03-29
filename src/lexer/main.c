/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:53:35 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:35 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	lexer(t_data *data)
{
	data->args = split_quotes(data->input, " ");
	if (!data->args)
	{
		free(data->input);
		return (0);
	}
	expand_args(data->args, data);
	data->args = subsplit_pipes_and_redirections(data->args);
	return (1);
}
