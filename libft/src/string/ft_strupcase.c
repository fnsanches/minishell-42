/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:35:00 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:37:29 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *s)
{
	char	*tmp;

	tmp = s;
	while (*s)
	{
		if (ft_islower(*s))
			*s = ft_toupper(*s);
		s++;
	}
	return (tmp);
}
