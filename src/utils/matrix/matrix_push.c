/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:51:51 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:38 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char **matrix_push(char **matrix, char *new)
{
	char **result;
	int i;
	int len;

	i = 0;
	if (!new)
		return (matrix);
	len = matrix_len(matrix);
	result = malloc(sizeof(char *) * (len + 2));
	result[len + 1] = NULL;
	if (!result)
		return (matrix);
	while (i < len)
	{
		result[i] = ft_strdup(matrix[i]);
		if (!result[i])
		{
			free_matrix(matrix);
			free_matrix(result);
		}
		i++;
	}
	result[i] = ft_strdup(new);
	free_matrix(matrix);
	return (result);
}
