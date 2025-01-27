/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:43:12 by frlorenz          #+#    #+#             */
/*   Updated: 2023/10/16 14:49:53 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	t_list	*item;

	nlist = NULL;
	if (!lst && !f)
		return (0);
	while (lst)
	{
		item = ft_lstnew(lst->content);
		if (!item)
		{
			ft_lstclear(&nlist, del);
			return (0);
		}
		item->content = f(item->content);
		ft_lstadd_back(&nlist, item);
		lst = lst->next;
	}
	return (nlist);
}
