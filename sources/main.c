#include "match_star.h"

int	main(int argc, char **argv)
{
	t_list	*filename_list;

	// Doesn't work if the last str after last bar is dir
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of params", 2);
		return (1);
	}
	filename_list = ft_expand_star(argv[1]);
	if (!filename_list)
		ft_putendl_fd("no matches found", 1);
	else
	{
		ft_print_filename_list(filename_list);
		ft_lstclear(&filename_list, &ft_del_content);
	}
	return (0);
}
