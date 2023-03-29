/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:50:12 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:39 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_input(t_data *data)
{
	int	status;

	status = 1;
	if (is_invalid_input(data->input))
		return (get_invalid_input_status(data->input));
	add_history(data->input);
	if (!lexer(data))
		return (throw_error(QUOTE, 1, NULL));
	parse_args(data);
	status = executor(data);
	clean(data);
	return (status);
}
