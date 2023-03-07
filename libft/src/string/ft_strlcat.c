/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:19:59 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:20:20 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = -1;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (!size || dstlen > size)
		return (srclen + size);
	while (src[++i] && dstlen + i < size - 1)
		dst[dstlen + i] = src[i];
	dst[i + dstlen] = '\0';
	return (srclen + dstlen);
}
