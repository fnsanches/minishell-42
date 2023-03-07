/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:15:38 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:02:49 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int		r;
	int				neg;

	r = 0;
	neg = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		neg = 1;
	if (*str == '+' || neg)
		str++;
	while (ft_isdigit(*str))
		r = r * 10 + (*str++ - '0');
	if (neg)
		return (-r);
	return (r);
}
