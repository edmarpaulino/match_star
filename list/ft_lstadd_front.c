#include "list.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!lst || !new)
		return ;
	aux = *lst;
	*lst = new;
	(*lst)->next = aux;
}
