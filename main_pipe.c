/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/07 20:43:25 by skohraku         ###   ########.fr       */
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

void		pipe_executor(int cmd_num, char ***cmd, char **env)
{
	int		fd[2];
	pid_t	pid1;

	if (cmd_num == 1)
	{
		if (execve(cmd[0][0], cmd[0], 0) < 0)
			ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
	else
	{
		pipe(fd);
		pid1 = fork();
		if (pid1 != 0)
		{
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
			/* 親プロセスにn番目のコマンドを実行させる */
			if (execve(cmd[cmd_num - 1][0], cmd[cmd_num - 1], env) == -1)
				ft_putendl_fd(strerror(errno), 2);
			exit(1);
		}
		else
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
			/* 子供プロセスには再帰でn-1番目のコマンドを実行させる */
			cmd_num--;
			pipe_executor(cmd_num, cmd, env);
		}
	}
}

void	executor(int cmd_num, char ***cmd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		pipe_executor(cmd_num, cmd, env);
	else
		wait(NULL);
}

int		main(int ac, char **av, char **env)
{
	char	***cmdlst;
	//pid_t	pid;
	int 	i;
	int		cmd_num;

	i = 0;
	cmd_num = ac - 1;
	cmdlst = malloc(sizeof(char **) * (cmd_num + 1));
	cmdlst[cmd_num] = NULL;
	while (i < cmd_num)
	{
		cmdlst[i] = ft_split(av[i+1], ' ');
		i++;
	}
	executor(cmd_num, cmdlst, env);

	//pid = fork();
	//if (pid == 0)
	//	pipe_executor(cmd_num, cmdlst, env);
	//else
	//	wait(NULL);
#if 0
	i = 0;
	while (cmdlst[i] != NULL)
		array_free(cmdlst[i++]);
	free(cmdlst);
#endif
	return (0);
}
