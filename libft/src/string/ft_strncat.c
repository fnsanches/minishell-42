/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:22:38 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:22:56 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	int		i;
	size_t	e;

	e = -1;
	i = ft_strlen(s1) - 1;
	while (s2[++e] && e < len)
		s1[++i] = s2[e];
	s1[++i] = '\0';
	return (s1);
}
