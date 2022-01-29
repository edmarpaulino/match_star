#include "match_star.h"

int	match_star(char *pattern, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (pattern[i])
	{
		while (pattern[i] == '*' && pattern[i])
			i++;
		if (!pattern[i])
			break ;
		if (i == 0 && pattern[i] != str[j])
			return (0);
		while (str[j] != pattern[i] && str[j])
			j++;
		if (!str[j])
			return (0);
		i++;
		j++;
	}
	if (!pattern[i] && pattern[i - 1] != '*' && str[j])
		return (0);
	return (1);
}
