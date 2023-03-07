/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:32:13 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:34:54 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	e;

	e = 0;
	i = ft_strlen(s);
	while (s[e] == ' ' || s[e] == ',' || s[e] == '\n' || s[e] == '\t')
		e++;
	if (e == i)
		return (ft_strnew(0));
	while (s[i - 1] == ' ' || s[i - 1] == ','
		|| s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	if (!(*s) || (!e && i == ft_strlen(s) - 1))
		return ((char *)s);
	else
		return (ft_strsub(s, e, i - e));
}
