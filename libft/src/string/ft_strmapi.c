/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:21:51 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:22:30 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;
	char			*tmp;

	str = ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	tmp = str;
	while (*s)
		*tmp++ = f(i++, *s++);
	return (str);
}
