/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:48:13 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/08 18:11:16 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include <unistd.h>
#include <dirent.h>
#include "libft.h"
#include "env_list.h"
#include "utils_string.h"
#include "utils.h"

static int	is_include(char *name, char c)
{
	int i;

	i = 0;
	while (name[i])
	{
		if (name[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		search_dir(char *path_i, char **arg)
{
	DIR				*dir;
	struct dirent	*ds;
	char			*full_path;

	ds = NULL;
	if (!(dir = opendir(path_i)))
		return (0);
	while ((ds = readdir(dir)) != NULL)
	{
		if (ft_strcmp(ds->d_name , *arg) == 0)
		{
			full_path = ft_join(ft_strdup(path_i), '/');
			*arg = ft_strjoin_free(full_path, *arg);
			closedir(dir);
			return (1);
		}
	}
	closedir(dir);
	return (0);
}

int			parse_path(char **arg)
{
	char	**path_lst;
	int		i;

	path_lst = ft_split(get_env_value("PATH"), ':');
	i = 0;
	while (path_lst[i])
	{
		if (search_dir(path_lst[i], arg) == 1)
		{
			array_free(path_lst);
			return (1);
		}
		i++;
	}
	if (path_lst != NULL)
		array_free(path_lst);
	return (0);
}

void		exec_execve(char **args, char **env, int fd)
{
	(void)fd;
	if (is_include(args[0], '/') < 0)
	{
		if (!parse_path(&args[0]))
		{
			ft_putstr_fd("shell: command not found: ", 2);
			ft_putendl_fd(args[0], 2);
			exit(EXIT_FAILURE);
		}
	}
	if ((execve(args[0], args, env)) == -1)
	{
		ft_putstr_fd("shell: ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	exit(EXIT_FAILURE);
}
