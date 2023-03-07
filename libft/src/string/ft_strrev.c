/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:34:36 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 02:46:23 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *string)
{
	int			len;
	size_t		i;
	char		temp;

	len = ft_strlen(string);
	i = -1;
	while (++i < ft_strlen(string) / 2)
	{
		temp = string[i];
		string[i] = string[len - i - 1];
		string[len - i - 1] = temp;
	}
	return (string);
}
