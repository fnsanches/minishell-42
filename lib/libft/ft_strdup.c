/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:57:30 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:59:51 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strdup(const char *s1)
{
	size_t len;
	char *result;

	len = ft_strlen(s1) + 1;
	result = malloc(sizeof(char) * len);
	if (!result)
		return (NULL);
	result = ft_memcpy(result, s1, len);
	return (result);
}
