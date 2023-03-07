/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:28:20 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/21 21:34:51 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*node;
	t_list	*tmp;

	node = *alst;
	while (node)
	{
		tmp = node->next;
		ft_lstdelone(&node, del);
		node = tmp;
	}
	*alst = NULL;
}
