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
# define STAR '*'

void	ft_get_filename_list(t_list **list, char *pattern, DIR *folder, char *path);
void	ft_print_filename_list(t_list *filename_list);
void	ft_del_content(void *content);
int		match_star(char *pattern, char *text);
int		ft_is_dot_dir(char *dir);
int		ft_is_root_dir(char *dir);
t_list	*ft_expand_star(char *path);
t_list	*ft_get_path_parts(char *str);

#endif