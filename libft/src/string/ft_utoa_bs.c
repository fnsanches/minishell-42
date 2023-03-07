/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:38:56 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 02:45:31 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(char *str, uintmax_t n, int base)
{
	const char		digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int				i;
	unsigned int	remain;

	if ((base < 2) || (base > 36))
		return (NULL);
	i = 0;
	while (n != 0)
	{
		remain = n % base;
		str[i++] = digits[remain];
		n /= base;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
