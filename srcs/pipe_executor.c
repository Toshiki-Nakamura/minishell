/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/21 22:31:42 by tnakamur         ###   ########.fr       */
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
#include "pipe_executor.h"

static int	get_child_process_result_from(int status)
{
	int	result;

	if (WIFEXITED(status))
	{
		result = WEXITSTATUS(status);
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

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, NULL, 0);
	return (get_child_process_result_from(status));
}

static void	recursive_pipe_exec(int fd[2], int std_fd, char **pipe_list)
{
	int	ret_value;

	ret_value = 0;
	if (std_fd == STDIN)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
		ret_value = exec_pipe_command(&pipe_list[1]);
		exit(ret_value);
	}
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	ret_value = exec_command(pipe_list[0]);
	exit(ret_value);
}

int			exec_pipe_command(char **pipe_list)
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
		recursive_pipe_exec(fd, STDIN, pipe_list);
	}
	signal(SIGINT, sig_ignore);
	pid2 = fork();
	if (pid2 == 0)
	{
		recursive_pipe_exec(fd, STDOUT, pipe_list);
	}
	ret_value = parent_wait(pid1, pid2, fd);
	return (ret_value);
}

int			fork_exec_commands(char **pipe_list)
{
	pid_t	pid;
	int		ret_value;
	int		status;

	ret_value = 0;
	pid = fork();
	signal(SIGINT, in_process);
	(!pipe_list[1]) ? signal(SIGQUIT, in_process) : signal(SIGQUIT, sig_ignore);
	if (pid == 0)
	{
		ret_value = exec_pipe_command(pipe_list);
		exit(ret_value);
	}
	wait(&status);
	return (get_child_process_result_from(status));
}
