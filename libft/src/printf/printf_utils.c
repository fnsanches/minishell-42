/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:54:36 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 02:53:17 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*ft_utoa(unsigned int num, char *str, int base)
{
	const char		digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int				i;
	unsigned int	remain;

	if ((base < 2) || (base > 36))
		return (NULL);
	i = 0;
	while (num != 0)
	{
		remain = num % base;
		str[i++] = digits[remain];
		num /= base;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

char	*ft_ultoa(unsigned long int num, char *str, int base)
{
	const char		digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int				i;
	unsigned int	remain;

	if ((base < 2) || (base > 36))
		return (NULL);
	i = 0;
	while (num != 0)
	{
		remain = num % base;
		str[i++] = digits[remain];
		num /= base;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
