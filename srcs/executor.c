/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:46:54 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/08 16:08:19 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/param.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "utils_string.h"
#include "builtin.h"

int		sh_launch(char **args, char **env, int fd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	/* printf("ppid = [%d]\n", pid); */
	if (pid == 0)
	{
		exec_execve(args, env, fd);
	}
	else if (pid < 0)
		perror("minish");
	else
	{
		wait(&status);
	}
	return (1);
}

/*
** @cmd_num = 複数コマンドの場合は1, 単体実行は0
*/
int		sh_execute(char **args, char **env, int fd, int cmd_num)
{
	if (args[0] == NULL)
	{
		return (1);
	}
	if (ft_strncmp_ex(args[0], "cd", 3) == 0)
	{
		return (exec_cd(args, env));
	}
	if (ft_strncmp_ex(args[0], "pwd", 4) == 0)
	{
		return (exec_pwd(fd));
	}
	if (ft_strncmp_ex(args[0], "env", 4) == 0)
	{
		return (exec_env(args, env, fd));
	}
	if (ft_strncmp(args[0], "exit", 5) == 0)
	{
		exec_exit(args);
	}
	if (ft_strncmp(args[0], "echo", 5) == 0)
	{
		return (exec_echo(args, fd));
	}
	if (ft_strncmp(args[0], "unset", 6) == 0)
	{
		return (exec_unset(args));
	}
	if (ft_strncmp(args[0], "export", 7) == 0)
	{
		return (exec_export(args, fd));
	}
	if (cmd_num)
	{
		exec_execve(args, env, fd);
		return (1);
	}
	return (sh_launch(args, env, fd));
}
