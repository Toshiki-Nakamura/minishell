/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/11 22:20:06 by tnakamur         ###   ########.fr       */
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
#include "executor.h"

static int	exec_pipe_command(int remain_cmd_num, char **pipe_list)
{
	int		fd[2];
	pid_t	pid;
	int		ret_value;

	if (remain_cmd_num == 0)
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
			ret_value = exec_command(pipe_list[remain_cmd_num]);
		}
		else
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
			/* 子供プロセスには再帰でn-1番目のコマンドを実行させる */
			ret_value = exec_pipe_command(remain_cmd_num - 1, pipe_list);
		}
	}
	return (ret_value);
}

int			fork_exec_commands(int cmd_num, char **pipe_list)
{
	pid_t	pid;
	int		ret_value;
	int		status;

	ret_value = 1; /* 0 でreturn するとinput_promptが終了してしまう */
	pid = fork();
	if (pid != 0)
	{
		wait(&status);
		/* 子プロセスの終了コード => $? */
		// if (WIFEXITED(status)) 
			// printf("[exit code = %d]\n", WEXITSTATUS(status));
		return (ret_value);
	}
	else
	{
		ret_value = exec_pipe_command(cmd_num - 1, pipe_list);
		//printf("child_process finished(%d)\n", ret_value);
		exit(1);// ? echo | cd => exit(0)
	}
}
