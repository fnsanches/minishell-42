/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:19:24 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 02:41:54 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	numsize(intmax_t n, int nlen, size_t radix)
{
	if (n < 0)
		nlen = ft_cntdigt_b(n, radix) + 1;
	else
		nlen = ft_cntdigt_b(n, radix);
}

void	ft_itoa_bs(char *dst, intmax_t n, char *base)
{
	size_t			radix;
	int				nlen;
	int				isneg;

	isneg = 0;
	nlen = 0;
	if (n < 0)
		isneg = -1;
	if (n == LONG_MIN)
	{
		ft_strcpy(dst, "-9223372036854775808");
		return ;
	}
	if (isneg)
		n = -n;
	radix = ft_strlen(base);
	numsize(n, nlen, radix);
	dst[0] = '\0';
	dst[nlen] = '\0';
	while (nlen--)
	{
		dst[nlen] = base[n % radix];
		n /= radix;
	}
	if (isneg)
		dst[0] = '-';
}
