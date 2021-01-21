/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:48:13 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/21 21:16:00 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include <unistd.h>
#include <dirent.h>
#include "libft.h"
#include "env_list.h"
#include "env_list_base.h"
#include "utils_string.h"
#include "utils.h"
#include "minishell.h"

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
		/* if (ft_strcmp(ds->d_name , *arg) == 0) */
		if (ft_cmp_ignore_case(*arg, ds->d_name, ft_strlen(*arg) + 1) == 0)
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

static int			is_dir(char *arg)
{
	DIR				*dir;

	if (!(dir = opendir(arg)))
		return (0);
	closedir(dir);
	return (1);
}

int			parse_path(char **arg)
{
	char	**path_lst;
	int		i;

	if (!(path_lst = ft_split(get_env_value("PATH"), ':')))
		return (0);
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

int		exec_execve(char **args, char **env)
{
	unsigned int	status;
	char			*err_msg;

	status = EXIT_FAILURE;
	if (is_include(args[0], '/') < 0 && get_env_value("PATH"))
	{
		if (!parse_path(&args[0]))
			return (error_handle(args[0], NULL, NOT_COMMAND, EXIT_NOT_CMD));
	}
	if ((execve(args[0], args, env)) == -1)
	{
		// ft_putstr_fd("\e[31merror: \e[0m", 2);
		err_msg = strerror(errno);
		if (errno == 13) /* permission err */
		{
			if (!is_dir(args[0]))
				status = error_handle(args[0], NULL, err_msg, EXIT_PERMIT);
			else
				status = error_handle(args[0], NULL, IS_DIR, EXIT_PERMIT);
		}
		else if (!parse_path(&args[0]) && errno == 2)
			status = error_handle(args[0], NULL, err_msg, EXIT_NOT_CMD);
	}
	return (status);
}
