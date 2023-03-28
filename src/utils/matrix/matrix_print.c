/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:51:55 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:38 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void print_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix && matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}
