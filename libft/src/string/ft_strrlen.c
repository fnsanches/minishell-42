/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:29:23 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:31:07 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strrlen(const char *s, char c)
{
	const char	*tmp;

	tmp = s;
	while (*tmp && *tmp != c)
		tmp++;
	return (tmp - s);
}
