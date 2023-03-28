/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:52:10 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:37 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char **dup_matrix(char **matrix)
{
	char **result;
	int i;

	i = 0;
	result = malloc(sizeof(char *) * (matrix_len(matrix) + 1));
	if (!result)
		return (NULL);
	while (matrix && matrix[i])
	{
		result[i] = ft_strdup(matrix[i]);
		if (!result[i])
		{
			free_matrix(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
