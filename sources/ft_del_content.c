#include "match_star.h"

void	ft_del_content(void *content)
{
	if (!content)
		return ;
	free(content);
	content = NULL;
}
