/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edpaulin <edpaulin@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:37:26 by edpaulin          #+#    #+#             */
/*   Updated: 2022/01/26 14:48:17 by edpaulin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Counts the number of elements in a list.
*
*	RETURN VALUES
*	Length of the list.
*/

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		size;

	if (!lst)
		return (0);
	aux = lst;
	size = 0;
	while (aux)
	{
		size++;
		aux = aux->next;
	}
	return (size);
}
