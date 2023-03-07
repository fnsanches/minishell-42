/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrequ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:25:21 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:26:31 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!(ft_strncmp(s1, s2, n)))
	{
		if (!s1 || !s2)
			return (0);
		return (1);
	}
	return (0);
}
