/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 19:58:58 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/07 15:52:22 by tnakamur         ###   ########.fr       */
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

static char	*ft_join(char *s, char c)
{
	char	*new;
	size_t	i;

	if (!(new = malloc(ft_strlen(s) + 2)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = s[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (s != NULL)
	{
		free(s);
	}
	return (new);
}

static char	*get_cmd_line(void)
{
	char	*line;
	char	buf;
	int		ret;

	line = ft_strdup("");
	while ((ret = read(0, &buf, 1)))
	{
		if (buf == '\n')
			break ;
		line = ft_join(line, buf);
	}
	if (ret == -1)
		exit(0);
	return (line);
}

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

void		pipe_executor(int n, char ***cmd, char **env)
{
	int		fd[2];
	pid_t	pid1;

	if (n - 1 != 0)
	{
		pipe(fd);
		pid1 = fork();
		if (pid1 == 0)
		{
			close(fd[0]);
			dup2(fd[1], 1);
			close(fd[1]);
			/* 子供プロセスには再帰でn-1番目のコマンドを実行させる */
			pipe_executor(--n, cmd, env);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
			/* 親プロセスにn番目のコマンドを実行させる */
			if (execve(cmd[n - 1][0], cmd[n - 1], env) == -1)
				ft_putendl_fd(strerror(errno), 2);
			exit(1);
		}
	}
	else
	{
		if (execve(cmd[0][0], cmd[0], 0) < 0)
			ft_putendl_fd(strerror(errno), 2);
		exit(1);
	}
}

int		main(int ac, char **av, char **env)
{
	char	*line;
	char	**args;
	char	***cmdlst;
	pid_t	pid;

	cmdlst = NULL;
	while (1)
	{
		write(1, "minishell $> ", 14);

		line = get_cmd_line();
		args = ft_split(line, '|');
		int len = array_size(args);
		cmdlst = malloc(sizeof(char **) * (len + 1));
		int i = -1;
		while (args[++i])
			cmdlst[i] = ft_split(args[i], ' ');
		cmdlst[i] = NULL;

		if (cmdlst[0])
		{
			pid = fork();
			if (pid == 0)
				pipe_executor(len, cmdlst, env);
			else
				wait(NULL);
		}

		if (line != NULL)
			free(line);
		if (args != NULL)
			array_free(args);
		i = 0;
		while (cmdlst[i] != NULL)
			array_free(cmdlst[i++]);
		free(cmdlst);
	}
	return (0);
}
