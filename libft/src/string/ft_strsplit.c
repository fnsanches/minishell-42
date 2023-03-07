/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:29:41 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:30:58 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		wi;
	int		wc;
	char	**dst;

	wc = ft_cntword(s, c);
	dst = (char **)ft_memalloc(sizeof(char *) * (wc + 1));
	if (!dst)
		return (NULL);
	if (!ft_strlen(s))
		return (dst);
	wi = -1;
	while (++wi < wc)
	{
		while (*s == c)
			s++;
		dst[wi] = ft_strndup(s, ft_strrlen(s, c));
		s += ft_strrlen(s, c);
	}
	dst[wi] = 0;
	return (dst);
}
