/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:18:31 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/25 13:30:01 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "utils.h"
#include "utils_string.h"
#include "env_list.h"
#include "msutils_env_param.h"

static void	set_pwd()
{
	char		path[MAXPATHLEN];
	char		*new;
	char		*old;

	old = ft_strjoin("OLDPWD=", get_env_value("PWD"));
	set_env_value(old);
	free(old);
	if (getcwd(path, MAXPATHLEN) == 0)
		ft_putendl_fd(strerror(errno), 2);
	new = ft_strjoin("PWD=", path);
	set_env_value(new);
	free(new);
}

int			exec_cd(char **args)
{
	const char	*home;

	home = get_env_value("HOME");
	if (!home && !args[1])
		return (error_handle("cd", NULL, "HOME not set", 1));
	else if (!args[1])
	{
		if (chdir(home) != 0)
			return (error_handle("cd", (char *)home, strerror(errno), 1));
	}
	else if (args[1][0] != '\0')
	{
		if (chdir(args[1]) != 0)
			return (error_handle("cd", args[1], strerror(errno), 1));
	}
	set_pwd();
	return (0);
}
