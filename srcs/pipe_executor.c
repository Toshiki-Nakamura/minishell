/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/04 16:54:04 by tnakamur         ###   ########.fr       */
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
#include "signal_handle.h"
#include "env_list.h"
#include "utils_string.h"
#include "utils.h"
#include "minishell.h"

static int	parent_wait(pid_t pid, pid_t pid2, int fd[2])
{
	int status;
	int ret_value;

	close(fd[0]); // 親プロセスはパイプfdを使わないので必ず閉じること
	close(fd[1]);
	waitpid(pid, &status, 0);
	waitpid(pid2, NULL, 0);
	if (WIFEXITED(status))
	{
		ret_value =  WEXITSTATUS(status);
	}
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		ret_value = EXIT_INVALID + SIGINT;
	}
	else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
	{
		ret_value = EXIT_INVALID + SIGQUIT;
	}
	return (ret_value);
}

static int	exec_pipe_command(int remain_cmd_num, char **pipe_list)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		ret_value;

	if (remain_cmd_num == 0)
	{
		ret_value = exec_command(pipe_list[0]);
	}
	else
	{
		pipe(fd);
		pid1 = fork();
		if (pid1 == 0)
		{
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
			/* 子プロセス1にn番目のコマンドを実行させる(元々は親プロセスが実行していた) */
			ret_value = exec_command(pipe_list[remain_cmd_num]);
		}
		else
		{
			pid2 = fork();
			if (pid2 == 0)
			{
				close(fd[0]);
				dup2(fd[1], 1);
				close(fd[1]);
				/* 子プロセス2には再帰でn-1番目のコマンドを実行させる */
				ret_value = exec_pipe_command(remain_cmd_num - 1, pipe_list);
			}
			ret_value = parent_wait(pid1, pid2, fd); /* 親たちはここで待機し,子プロセスの結果を返す */
		}
	}
	return (ret_value);
}

int			fork_exec_commands(int cmd_num, char **pipe_list)
{
	pid_t	pid;
	int		ret_value;
	int		status;

	ret_value = 0;
	pid = fork();
	signal(SIGINT, sig_process);
	signal(SIGQUIT, sig_process);
	if (pid != 0)
	{
		wait(&status);
		/* 子プロセスの終了コード => $? */
		if (WIFEXITED(status))
		{
			ret_value =  WEXITSTATUS(status);
		}
		if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
		{
			ret_value = EXIT_INVALID + SIGINT;
		}
		else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
		{
			ret_value = EXIT_INVALID + SIGQUIT;
		}
		// printf("[exit code = %d]\n", ret_value);
		return (ret_value);
	}
	else
	{
		ret_value = exec_pipe_command(cmd_num - 1, pipe_list);
		//printf("child_process finished(%d)\n", ret_value);
		// system("leaks minishell");
		exit(ret_value);// ? echo | cd => exit(retvalue)
	}
}
