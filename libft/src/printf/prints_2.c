/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:19:28 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 02:47:56 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_putunsigned(unsigned int num)
{
	int		len;
	char	*nb;

	len = 0;
	nb = (char *)malloc(17 * sizeof(char));
	if (num == 0)
		len += write(1, "0", 1);
	ft_utoa(num, nb, 10);
	len += len_putstr(nb);
	free(nb);
	return (len);
}
