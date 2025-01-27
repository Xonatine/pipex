/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlorenz <frlorenz@student.42madrid.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:35:08 by frlorenz          #+#    #+#             */
/*   Updated: 2023/10/16 17:46:06 by frlorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*head;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		head = *lst;
		del (head->content);
		*lst = head->next;
		free (head);
	}
}
