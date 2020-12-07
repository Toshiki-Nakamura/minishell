/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/07 21:07:46 by skohraku         ###   ########.fr       */
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

static void	execve_implement(char **cmd)
{
	if (execve(cmd[0], cmd, g_env) == -1)
		ft_putendl_fd(strerror(errno), 2);
}


void		pipe_executor(int cmd_num, char ***cmd)
{
	int		fd[2];
	pid_t	pid;

	cmd_num--;
	if (cmd_num == 0)
	{
		execve_implement(cmd[0]);
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
		execve_implement(cmd[cmd_num]);
		exit(1);
	}
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	/* 子供プロセスには再帰でn-1番目のコマンドを実行させる */
	pipe_executor(cmd_num, cmd);
}

void	executor(int cmd_num, char ***cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid != 0)
	{
		//printf("parent process wait(%d)\n", pid);
		wait(NULL);
		//printf("parent process wakeup\n");
	}
	else
	{
		//printf("child process(%d)\n", pid);
		pipe_executor(cmd_num, cmd);
	}
}

int		main(int ac, char **av, char **env)
{
	char	***cmdlst;
	int 	i;
	int		cmd_num;

	g_env = env;
	i = 0;
	cmd_num = ac - 1;
	cmdlst = malloc(sizeof(char **) * (cmd_num + 1));
	cmdlst[cmd_num] = NULL;
	while (i < cmd_num)
	{
		cmdlst[i] = ft_split(av[i+1], ' ');
		i++;
	}
	executor(cmd_num, cmdlst);

#if 0
	i = 0;
	while (cmdlst[i] != NULL)
		array_free(cmdlst[i++]);
	free(cmdlst);
#endif
	return (0);
}
