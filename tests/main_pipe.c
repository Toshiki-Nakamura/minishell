/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/07 21:47:31 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <sys/param.h>
# include <signal.h>
# include "libft.h"

#if 0
void	array_free(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

int		array_size(char **array)
{
	int i = 0;
	while (array[i])
		i++;
	return (i);
}
#endif


static char	**g_env;

static void	exec_command(char *cmd)
{
	char	**cmd_list;

	cmd_list = ft_split(cmd, ' ');
	if (execve(cmd_list[0], cmd_list, g_env) == -1)
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

static void	exec_pipe_list(int cmd_num, char **pipe_list)
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

int		main(int ac, char **av, char **env)
{
	// execveで引数に必要なためグローバル変数に保持しておく。
	g_env = env;
	/* shell> ls | cat -e | grep test を入力した場合、
	* pipe_listは、"ls", "cat -e", "grep test" の形式。
	* テスト用のmainでは、avをそのまま使用する。
	*/
	exec_pipe_list(ac - 1, &av[1]);
	return (0);
}
