/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/08 17:00:00 by skohraku         ###   ########.fr       */
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

static int	get_child_process_result_from(int status)
{
	int	result;

	if (WIFEXITED(status))
	{
		result =  WEXITSTATUS(status);
	}
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		result = EXIT_INVALID + SIGINT;
	}
	else if (WIFSIGNALED(status) && WTERMSIG(status) == SIGQUIT)
	{
		result = EXIT_INVALID + SIGQUIT;
	}
	return (result);
}

static int	parent_wait(pid_t pid1, pid_t pid2, int fd[2])
{
	int status;

	close(fd[0]); // 親プロセスはパイプfdを使わないので必ず閉じること
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, NULL, 0);
	return (get_child_process_result_from(status));
}

static int	exec_pipe_command(char **pipe_list)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		ret_value;

	if (pipe_list[1] == NULL)
	{
		ret_value = exec_command(pipe_list[0]);
		return (ret_value);
	}
	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		/* 子プロセス1には再帰で次のコマンドを実行させる */
		ret_value = exec_pipe_command(&pipe_list[1]);
		exit(ret_value);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		/* 子プロセス2に先頭のコマンドを実行させる */
		ret_value = exec_command(pipe_list[0]);
		exit(ret_value);
	}
	ret_value = parent_wait(pid1, pid2, fd); /* 親たちはここで待機し,子プロセスの結果を返す */
	return (ret_value);
}

int			fork_exec_commands(char **pipe_list)
{
	pid_t	pid;
	int		ret_value;
	int		status;

	ret_value = 0;
	pid = fork();
	signal(SIGINT, sig_process);
	signal(SIGQUIT, sig_process);
	if (pid == 0)
	{
		ret_value = exec_pipe_command(pipe_list);
		//printf("child_process finished(%d)\n", ret_value);
		// system("leaks minishell");
		exit(ret_value);// ? echo | cd => exit(retvalue)
	}
	wait(&status);
	/* 子プロセスの終了コード => $? */
	// printf("[exit code = %d]\n", ret_value);
	return (get_child_process_result_from(status));
}
