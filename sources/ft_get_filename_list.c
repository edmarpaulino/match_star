#include "match_star.h"

void	ft_get_filename_list(t_list **list, char *pattern, DIR *folder, char *path)
{
	t_list			*new;
	struct dirent	*entry;

	if (!pattern || !folder)
		return ;
	entry = readdir(folder);
	while (entry)
	{
		if (match_star(pattern, entry->d_name) && !ft_is_dot_dir(entry->d_name))
		{
			new = ft_lstnew(ft_strjoin(path, entry->d_name));
			if (!new)
			{
				ft_lstclear(list, &ft_del_content);
				return ;
			}
			ft_lstadd_back(list, new);
		}
		entry = readdir(folder);
	}
}
