/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:51:45 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:38 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**matrix_remove(char **matrix, int to_remove)
{
	char	**result;
	int		i;
	int		j;
	int		len;

	if (!matrix || !matrix[to_remove])
		return (matrix);
	i = 0;
	j = 0;
	len = matrix_len(matrix);
	result = malloc(sizeof(char *) * (len));
	result[len] = NULL;
	if (!result)
		return (matrix);
	while (i < len)
	{
		if (i != to_remove)
			result[j++] = ft_strdup(matrix[i]);
		i++;
	}
	free_matrix(matrix);
	return (result);
}
