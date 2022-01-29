#ifndef MATCH_STAR_H
# define MATCH_STAR_H

# include <stdio.h>
# include <dirent.h>
# include "libft.h"

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

t_list	*ft_get_filename_list(char *pattern, DIR *folder);
void	ft_print_filename_list(t_list *filename_list);
void	ft_del_content(void *content);
int		match_star(char *pattern, char *str);
int		ft_is_dot_dir(char *dir);

#endif