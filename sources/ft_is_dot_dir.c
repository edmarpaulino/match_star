#include "match_star.h"

int	ft_is_dot_dir(char *dir)
{
	if (!dir)
		return (0);
	return (!ft_strcmp(dir, ".") || !ft_strcmp(dir, ".."));
}
