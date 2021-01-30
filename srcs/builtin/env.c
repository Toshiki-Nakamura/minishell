/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:14:10 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/25 19:48:55 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "env_list.h"
#include "env_show.h"
#include "utils.h"
#include "utils_string.h"
#include "minishell.h"

static int	path_check(char **path, char **key)
{
	char	**array;
	int		i;
	int		size;

	i = -1;
	array = NULL;
	while (path[++i])
	{
		if (!ft_strncmp(path[i], "/usr/bin/", 9) || \
						!ft_strcmp(path[i], "/usr/bin"))
		{
			array = ft_split(path[i], '/');
			size = array_size(array);
			if (array)
				array_free(array);
			if (size == 2)
			{
				*key = ft_strjoin("_=", path[i]);
				array_free(path);
				return (1);
			}
		}
	}
	array_free(path);
	return (0);
}

int			exec_env(char **args)
{
	const char	*path;
	char		**path_lst;
	char		*cmd;
	char		*key;

	if (args[1] != NULL)
		return (error_handle(args[0], NULL, MINISHELL_ERROR_ARG, EXIT_USAGE));
	path = get_env_value("PATH");
	if (!path || !ft_strcmp(path, ""))
		return (error_handle(args[0], NULL, strerror(2), EXIT_NOT_CMD));
	path_lst = ft_split(path, ':');
	if (path_check(path_lst, &key) == 0)
		return (error_handle(args[0], NULL, NOT_COMMAND, EXIT_NOT_CMD));
	if (ft_strcmp(key, "_=/usr/bin") == 0)
		key = ft_join(key, '/');
	if (!(cmd = ft_strjoin(key, args[0])))
		error_force_exit(MALLOC_ERROR);
	set_env_value(cmd);
	free(cmd);
	free(key);
	show_env_list();
	return (0);
}
