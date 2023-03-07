/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:22:57 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:23:17 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	if (!n)
		return (0);
	i = 0;
	tmp1 = (const unsigned char *)s1;
	tmp2 = (const unsigned char *)s2;
	while ((i + 1) < n && tmp1[i] && tmp2[i] && tmp1[i] == tmp2[i])
		i++;
	return (tmp1[i] - tmp2[i]);
}
