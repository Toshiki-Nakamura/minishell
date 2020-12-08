/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/08 18:50:52 by tnakamur         ###   ########.fr       */
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
#include "env_list.h"
#include "env_list_base.h"

int			exec_command(char *cmd)
{
	char	**cmd_list;
	int		ret_value;

	cmd_list = ft_split(cmd, ' ');
	ret_value = sh_execute(cmd_list, get_env_param(), 1, 1);
	if (ret_value == -1)
		ft_putendl_fd(strerror(errno), 2);
	return (ret_value);
}

static int	exec_pipe_commands(int cmd_num, char **pipe_list)
{
	int		fd[2];
	pid_t	pid;
	int		ret_value;

	if (cmd_num == 0)
	{
		ret_value = exec_command(pipe_list[0]);
	}
	else
	{
		pipe(fd);
		pid = fork();
		if (pid != 0)
		{
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
			/* 親プロセスにn番目のコマンドを実行させる */
			ret_value = exec_command(pipe_list[cmd_num]);
		}
		else
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
			/* 子供プロセスには再帰でn-1番目のコマンドを実行させる */
			ret_value = exec_pipe_commands(cmd_num - 1, pipe_list);
		}
	}
	return (ret_value);
}

int			exec_pipe_list(int cmd_num, char **pipe_list)
{
	pid_t	pid;
	int		ret_value;

	ret_value = 1; /* 0 でreturn するとinput_promptが終了してしまう */
	pid = fork();
	if (pid != 0)
	{
		wait(NULL);
		return (ret_value);
	}
	else
	{
		ret_value = exec_pipe_commands(cmd_num - 1, pipe_list);
		//printf("child_process finished(%d)\n", ret_value);
		exit(1);
	}
}
