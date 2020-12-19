/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:18:31 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/19 14:34:56 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"

static void	set_pwd()
{
	char		path[MAXPATHLEN];
	char		*new;
	char		*old;

	old = ft_strjoin("OLDPWD=", get_env_value("PWD"));
	set_env_value(old);
	free(old);
	if (getcwd(path, MAXPATHLEN) == 0)
		ft_putendl_fd(strerror(errno), 1);
	new = ft_strjoin("PWD=", path);
	set_env_value(new);
	free(new);
}

int			exec_cd(char **args, char **env)
{
	const char	*home = get_env_value("HOME");

	(void)env;
	if (args[1] == NULL || !ft_strncmp("~/", args[1], 3) ||\
						 !ft_strncmp("~", args[1], 2))
	{
		if (chdir(home) != 0)
		{
			ft_putendl_fd(strerror(errno), 2);
			return (1);
		}
	}
	else
	{
		// error -1, success  0
		if (chdir(args[1]) != 0)
		{
			ft_putendl_fd(strerror(errno), 2);
			return (1);
		}
	}
	set_pwd();
	return (0);
}
