#include "match_star.h"

static int	ft_is_root_dir(char *arg)
{
	if (!arg)
		return (0);
	return (arg[0] == '/' && !ft_strchr(arg + 1, '/'));
}

static void	ft_separate_pattern_from_path(char *arg, char **pattern, char **path)
{
	if (!arg || !pattern || !path)
		return ;
	if (ft_is_root_dir(arg))
	{
		if (ft_strlen(arg) == 1)
		{
			*pattern = "*";
			*path = ft_strdup(arg);
		}
		else
		{
			*pattern = arg + 1;
			*path = ft_strdup("/");
		}
		return ;
	}
	*pattern = ft_strrchr(arg, '/');
	if (!*pattern)
	{
		if (ft_is_dot_dir(arg))
		{
			*pattern = "*";
			*path = ft_strdup(arg);
		}
		else
		{
			*pattern = arg;
			*path = ft_strdup(".");
		}
	}
	else
	{
		*path = ft_substr(arg, 0, *pattern - arg);
		(*pattern)++;
		if (**pattern == '\0')
			*pattern = "*";
	}
}

int	main(int argc, char **argv)
{
	DIR		*folder;
	t_list	*filename_list;
	char	*pattern;
	char	*path;

	// Doesn't work if the last str after last bar is dir
	if (argc != 2)
	{
		ft_putendl_fd("Wrong number of params", 2);
		return (1);
	}
	pattern = NULL;
	path = NULL;
	ft_separate_pattern_from_path(argv[1], &pattern, &path);
	if (!path)
		return (1);
	folder = opendir(path);
	free(path);
	if (!folder)
		return (1);
	filename_list = ft_get_filename_list(pattern, folder);
	if (!filename_list)
		ft_putendl_fd("no matches found", 1);
	else
	{
		ft_print_filename_list(filename_list);
		ft_lstclear(&filename_list, &ft_del_content);
	}
	closedir(folder);
	return (0);
}

// int	main(void)
// {
// 	int		i;
// 	char	*str = "hello.c";
// 	char	*pattern[] = { "hello.", "*.c", "h*", "h*.c", "h*ll*.c", "********h***e***l****", "", NULL };

// 	i = 0;
// 	while (pattern[i])
// 	{
// 		match_star(pattern[i], str) ? ft_putendl_fd("true", 1) : ft_putendl_fd("false", 1);
// 		i++;
// 	}

// 	return (0);
// }