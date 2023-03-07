/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:21:07 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:21:42 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	char	*tmp;

	str = ft_strdup(s);
	if (!str)
		return (NULL);
	tmp = str;
	while (*s)
		*tmp++ = f(*s++);
	return (str);
}
