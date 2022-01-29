#include "match_star.h"

void	ft_print_filename_list(t_list *filename_list)
{
	if (!filename_list)
		return ;
	while (filename_list)
	{
		ft_putendl_fd((char *)filename_list->content, 1);
		filename_list = filename_list->next;
	}
}
