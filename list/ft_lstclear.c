#include "list.h"

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
