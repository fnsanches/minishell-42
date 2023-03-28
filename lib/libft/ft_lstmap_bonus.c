/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsanches <fsanches@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:58:36 by fsanches          #+#    #+#             */
/*   Updated: 2023/03/27 20:59:50 by fsanches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *tail;

	if (!lst || !f)
		return (0);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	tail = head;
	lst = lst->next;
	while (lst)
	{
		tail->next = ft_lstnew(f(lst->content));
		if (!tail->next)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		tail = tail->next;
		lst = lst->next;
	}
	tail->next = NULL;
	return (head);
}
