/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:01:04 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/21 22:05:50 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	ft_freearray(void **array, size_t nmemb)
{
	size_t	i;

	i = -1;
	while (++i < nmemb)
		free(array[i]);
	free(array);
	array = NULL;
}
