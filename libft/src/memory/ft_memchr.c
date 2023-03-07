/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:01:12 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/21 22:08:20 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return ((void *)((char *)src + i));
	return (NULL);
}
