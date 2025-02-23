/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmesa-ke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 11:11:05 by vmesa-ke          #+#    #+#             */
/*   Updated: 2024/10/13 10:37:25 by vmesa-ke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	newnode = ft_lstnew(f(lst->content));
	if (!newnode)
		return (NULL);
	head = newnode;
	lst = lst->next;
	while (lst)
	{
		newnode->next = ft_lstnew (f (lst->content));
		if (!newnode->content)
		{
			ft_lstclear (&head, del);
			return (NULL);
		}
		newnode = newnode->next;
		lst = lst->next;
	}
	return (head);
}
