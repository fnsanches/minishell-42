/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:12:13 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:12:26 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	i = 0;
	tmp1 = (const unsigned char *)s1;
	tmp2 = (const unsigned char *)s2;
	while (tmp1[i] && tmp2[i] && tmp1[i] == tmp2[i])
		i++;
	return (tmp1[i] - tmp2[i]);
}
