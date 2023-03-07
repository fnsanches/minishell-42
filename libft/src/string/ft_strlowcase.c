/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:20:50 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:21:00 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *s)
{
	char	*tmp;

	tmp = s;
	while (*s)
	{
		if (ft_isupper(*s))
			*s = ft_tolower(*s);
		s++;
	}
	return (tmp);
}
