#include "match_star.h"

t_list	*ft_get_filename_list(char *pattern, DIR *folder)
{
	t_list			*filename_list;
	t_list			*new;
	struct dirent	*entry;

	if (!pattern || !folder)
		return (NULL);
	entry = readdir(folder);
	filename_list = NULL;
	while (entry)
	{
		if (match_star(pattern, entry->d_name) && !ft_is_dot_dir(entry->d_name))
		{
			new = ft_lstnew(entry->d_name);
			if (!new)
			{
				ft_lstclear(&filename_list, &ft_del_content);
				return (NULL);
			}
			ft_lstadd_back(&filename_list, new);
		}
		entry = readdir(folder);
	}
	return (filename_list);
}
