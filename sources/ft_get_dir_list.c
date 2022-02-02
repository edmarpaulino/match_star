#include "match_star.h"

static int	ft_add_part_to_list(t_list **list, char *part)
{
	t_list	*new;

	new = ft_lstnew(ft_strdup(part));
	if (!new)
		return (0);
	ft_lstadd_back(list, new);
	return (1);
}

t_list	*ft_get_path_parts(char *path)
{
	char	**splitted_path;
	t_list	*list_of_parts;
	int		i;

	list_of_parts = NULL;
	if (path[0] == '/')
	{
		if (!ft_add_part_to_list(&list_of_parts, "/"))
			return (NULL);
	}
	splitted_path = ft_split(path, '/');
	if (!splitted_path)
		return (NULL);
	i = 0;
	while (splitted_path[i])
	{
		if (!ft_add_part_to_list(&list_of_parts, splitted_path[i]))
		{
			ft_lstclear(&list_of_parts, &ft_del_content);
			return (NULL);
		}
		i++;
	}
	ft_clear_split(splitted_path);
	return (list_of_parts);
}