/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:16:36 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 00:59:44 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntword(const char *s, char c)
{
	int	res;

	if (!*s)
		return (0);
	if (!c && *s)
		return (1);
	if (*s == c)
		res = 0;
	else
		res = 1;
	while (*(s + 1))
	{
		if (*s == c && *(s + 1) != c)
			res += 1;
		s++;
	}
	return (res);
}
