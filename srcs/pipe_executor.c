/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/07 23:17:58 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include <signal.h>
#include "libft.h"
#include "executor.h"
#include "env_list_base.h"

static void	exec_command(char *cmd)
{
	char	**cmd_list;

	cmd_list = ft_split(cmd, ' ');
	if (sh_execute(cmd_list, get_env_param(), 1) <= 0)
		ft_putendl_fd(strerror(errno), 2);
}

static void	exec_pipe_commands(int cmd_num, char **pipe_list)
{
	int		fd[2];
	pid_t	pid;

	if (cmd_num == 0)
	{
		exec_command(pipe_list[0]);
		exit(1);
	}
	pipe(fd);
	pid = fork();
	if (pid != 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		/* 親プロセスにn番目のコマンドを実行させる */
		exec_command(pipe_list[cmd_num]);
		exit(1);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		/* 子供プロセスには再帰でn-1番目のコマンドを実行させる */
		exec_pipe_commands(cmd_num - 1, pipe_list);
	}
}

void		exec_pipe_list(int cmd_num, char **pipe_list)
{
	pid_t	pid;

	pid = fork();
	if (pid != 0)
	{
		wait(NULL);
	}
	else
	{
		exec_pipe_commands(cmd_num - 1, pipe_list);
	}
}
