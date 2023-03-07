/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:13:34 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:15:05 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;

	tmp = ft_strnew(ft_strlen(s1));
	if (!tmp)
		return (NULL);
	ft_strcpy(tmp, s1);
	return (tmp);
}
