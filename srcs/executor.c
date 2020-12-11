/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:46:54 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/11 22:17:36 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/param.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "utils_string.h"
#include "builtin.h"
#include "env_list_base.h"
#include "env_list.h"

int		is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (1);
	if (ft_cmp_ignore_case(cmd, "cd", 3) == 0)
		return (1);
	if (ft_cmp_ignore_case(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_cmp_ignore_case(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0) //完全一致で動作
		return (1);
	if (ft_cmp_ignore_case(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0) //完全一致で動作
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0) //完全一致で動作
		return (1);
	return (0);
}

int		sh_execute(char **args, char **env, int fd)
{
	if (args[0] == NULL)
		return (1);
	if (ft_strncmp(args[0], "cd", 3) == 0)
		return (exec_cd(args, env));
	else if (ft_cmp_ignore_case(args[0], "cd", 3) == 0)
		return (1);
	if (ft_cmp_ignore_case(args[0], "pwd", 4) == 0)
		return (exec_pwd(fd));
	if (ft_cmp_ignore_case(args[0], "env", 4) == 0)
		return (exec_env(args, env, fd));
	if (ft_strncmp(args[0], "exit", 5) == 0)
		exec_exit(args);
	if (ft_cmp_ignore_case(args[0], "echo", 5) == 0)
		return (exec_echo(args, fd));
	if (ft_strncmp(args[0], "unset", 6) == 0)
		return (exec_unset(args));
	if (ft_strncmp(args[0], "export", 7) == 0)
		return (exec_export(args, fd));
	exec_execve(args, env, fd);
	return (1);
}

int			exec_command(char *cmd)
{
	char	**cmd_list;
	int		ret_value;

	cmd_list = ft_split(cmd, ' ');
	ret_value = sh_execute(cmd_list, get_env_param(), 1);
	if (ret_value == -1)
		ft_putendl_fd(strerror(errno), 2);
	return (ret_value);
}
