/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 13:35:21 by skohraku         ###   ########.fr       */
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
#include "my_signal.h"
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

static void	close_and_dup(int fd[2], int std_fd)
{
	if (std_fd == STDIN)
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
	}
}

int			exec_pipe_command(char **pipe_list)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe_list[1] == NULL)
		return (exec_command(pipe_list[0]));
	pipe(fd);
	pid1 = fork();
	if (pid1 == 0)
	{
		close_and_dup(fd, STDIN);
		exit(exec_pipe_command(&pipe_list[1]));
	}
	signal(SIGINT, sig_ignore);
	pid2 = fork();
	if (pid2 == 0)
	{
		close_and_dup(fd, STDOUT);
		exit(exec_command(pipe_list[0]));
	}
	return (parent_wait(pid1, pid2, fd));
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
