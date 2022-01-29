#include "list.h"

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