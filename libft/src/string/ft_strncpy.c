/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:23:22 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:24:42 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	l;

	i = -1;
	l = ft_strlen(src);
	while (++i < len)
	{
		if (i < l)
			dst[i] = src[i];
		else
			dst[i] = '\0';
	}
	return (dst);
}
