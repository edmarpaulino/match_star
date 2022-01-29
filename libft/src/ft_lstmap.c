/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 16:55:30 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/26 11:50:56 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Iterates the list ’lst’ and applies the function ’f’ to the content of each
*	element. Creates a new list resulting of the successive applications of the
*	function ’f’. The ’del’ function is used to delete the content of an 
*	element if needed.
*
*	RETURN VALUES
*	The new list. NULL if the allocation fails.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*mapped;

	if (!lst || !f || !del)
		return (NULL);
	mapped = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&mapped, del);
			return (NULL);
		}
		ft_lstadd_back(&mapped, new);
		lst = lst->next;
	}
	return (mapped);
}
