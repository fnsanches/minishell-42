/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:29:15 by fsanches          #+#    #+#             */
/*   Updated: 2022/05/21 21:35:43 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnewl(void **ptr)
{
	t_list	*new;

	new = (t_list *)ft_memalloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!*ptr)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = *ptr;
		new->content_size = sizeof(void *);
	}
	new->next = NULL;
	return (new);
}
