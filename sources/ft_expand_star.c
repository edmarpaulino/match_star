#include "match_star.h"

// t_list	*ft_expand_star(char *path)
// {
// 	DIR		*folder;
// 	t_list	*filename_list;
// 	char	*pattern;
// 	char	*dir;

// 	pattern = NULL;
// 	dir = NULL;
// 	ft_get_dir_to_open(path, &pattern, &dir);
// 	if (!dir)
// 		return (NULL);
// 	folder = opendir(dir);
// 	free(dir);
// 	if (!folder)
// 		return (NULL);
// 	filename_list = ft_get_filename_list(pattern, folder);
// 	closedir(folder);
// 	return (filename_list);
// }

// Como definir o ponto de partida?
// O primeiro carácter é o /, se sim então é ele
// se não então é a primeira string do split
// o último split é o arquivo alvo

/*

/ home / * / * / *.c
start /
dir home
dir *
dir *
target *.c


. / * / *.c
start .
dir *
target *.c

Função recursiva
Toda chamada abre o diretório atual e fecha quando terminar todos os arquivos que derem match naquele diretório
Condição de parada = fim dos arquivos do diretório da chamada

Função que checa se o arquivo é um diretório

Adiciona o caminho na lista quando atingir o target e tiver dado match
*/

static int	ft_is_the_target(t_list *list)
{
	return (list->next == NULL);
}

static char	*ft_concat_path(char *last, char *next)
{
	char *concat;
	char *tmp;

	if (!ft_strcmp(last, "/"))
		concat = ft_strjoin(last, next);
	else
	{
		tmp = ft_strjoin(last, "/");
		concat = ft_strjoin(tmp, next);
		free(tmp);
	}
	return (concat);
}

static void	ft_get_expanded_values(t_list *values, t_list *dir, char *dir_open)
{
	char	*next_dir;

	// está no target? faça isso
	if (ft_is_the_target(dir))
	{
		printf("%s\n", dir_open);
		printf("I reach the target \\o/\n");
		printf("Target: %s\n======\n", (char *)dir->content);
		return ;
	}
	else // não está no target ainda? faça isso
	{
		printf("%s\n", dir_open);
		next_dir = ft_concat_path(dir_open, (char *)dir->content);
		ft_get_expanded_values(values, dir->next, next_dir);
		free(next_dir);
	}
}

t_list	*ft_expand_star(char *str)
{
	t_list	*expanded_values;
	t_list	*path_parts;

	expanded_values = NULL;
	path_parts = ft_get_path_parts(str);
	ft_get_expanded_values(expanded_values, path_parts->next, (char *)path_parts->content);
	return (path_parts);
}