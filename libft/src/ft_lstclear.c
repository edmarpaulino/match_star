/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:44:42 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/26 11:47:56 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Deletes and frees the given element and every successor of that element,
*	using the function ’del’ and free(3). Finally, the pointer to the list must
*	be set to NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**head;
	t_list	*aux;

	if (!lst || !del)
		return ;
	head = lst;
	while (*lst)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*head = NULL;
}
