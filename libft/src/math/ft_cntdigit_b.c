/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntdigit_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:36:49 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/21 21:40:10 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cntdigt_b(intmax_t n, size_t radix)
{
	size_t	r;

	r = 1;
	while (n >= (int)radix)
	{
		n /= radix;
		r++;
	}
	return (r);
}
