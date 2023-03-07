/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:28:08 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/21 21:35:54 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **src, t_list *new)
{
	t_list	*node;

	node = *src;
	while (node)
	{
		if (node->next)
			node = node->next;
		else
			break ;
	}
	node->next = new;
}
