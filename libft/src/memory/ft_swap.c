/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:01:37 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/21 22:08:47 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_swap(void *a, void *b, size_t size)
{
	char	*c;
	char	*d;
	char	tmp;
	size_t	i;

	if (a == b)
		return ;
	c = (char *)a;
	d = (char *)b;
	i = -1;
	while (++i != size)
	{
		tmp = c[i];
		c[i] = d[i];
		d[i] = tmp;
	}
}
