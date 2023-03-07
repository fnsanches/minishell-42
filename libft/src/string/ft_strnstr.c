/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:26:38 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:27:22 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	needle_len;

	if (!(*needle))
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && needle_len <= len--)
	{
		if (*haystack == *needle
			&& !(ft_memcmp(haystack, needle, needle_len)))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
