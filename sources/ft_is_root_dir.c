#include "match_star.h"

int	ft_is_root_dir(char *dir)
{
	if (!dir)
		return (0);
	return (dir[0] == '/' && !ft_strchr(dir + 1, '/'));
}