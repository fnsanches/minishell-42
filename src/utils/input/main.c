/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:52:22 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:37 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int is_empty(char *input)
{
	return (input && ft_strlen(input) == 0);
}

int is_null(char *input)
{
	return (input == NULL);
}

int get_invalid_input_status(char *input)
{
	if (is_null(input))
		return (0);
	return (1);
}

int is_invalid_input(char *input)
{
	return (is_empty(input) || is_null(input));
}
