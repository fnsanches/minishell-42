/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprecat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:27:32 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:28:58 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strprecat(char *dst, const char *src)
{
	size_t	l;

	l = ft_strlen(src);
	ft_memmove(dst + l, dst, ft_strlen(dst) + 1);
	return (ft_memcpy(dst, src, sizeof(char) * l));
}
