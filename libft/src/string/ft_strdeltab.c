/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeltab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 01:13:02 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/22 01:14:11 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdeltab(char **tab, size_t tab_len)
{
	size_t	i;

	i = -1;
	while (++i < tab_len)
		if (tab[i])
			ft_strdel(&tab[i]);
	free(tab);
	tab = NULL;
}
