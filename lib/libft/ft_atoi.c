/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:59:43 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:59:49 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f' || c == ' ');
}

int ft_atoi(const char *str)
{
	int sign;
	unsigned long int result;
	size_t i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] != '\0' && is_space(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		if (result >= 9223372036854775807 && sign == 1)
			return (-1);
		if (result > 9223372036854775807 && sign == -1)
			return (0);
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * sign);
}
