#include "list.h"

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
