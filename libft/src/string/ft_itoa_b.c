/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:18:38 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 00:18:52 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_b(intmax_t n, char *base)
{
	char	buf[ITOA_B_BUF];

	ft_itoa_bs(buf, n, base);
	return (ft_strdup(buf));
}
