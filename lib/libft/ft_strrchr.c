/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:56:34 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:59:52 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;
	char *result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			result = (char *)(s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		result = (char *)(s + i);
	return (result);
}
