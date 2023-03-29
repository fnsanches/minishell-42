/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:51:27 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:55:38 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*ft_strcat(char *src, char *dest)
{
	int		i;
	int		y;
	int		len;
	char	*result;

	i = 0;
	y = 0;
	len = (ft_strlen(src) + ft_strlen(dest));
	result = malloc(sizeof(char) * len + 1);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	while (dest[y] != '\0')
	{
		result[i] = dest[y];
		i++;
		y++;
	}
	result[i] = '\0';
	return (result);
}
