/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:37:41 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:41:28 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa_b(uintmax_t n, char *base)
{
	char	buf[ITOA_B_BUF];

	ft_utoa_bs(buf, n, base);
	return (ft_strdup(buf));
}
