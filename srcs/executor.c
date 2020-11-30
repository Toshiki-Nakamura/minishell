/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:46:54 by skohraku          #+#    #+#             */
/*   Updated: 2020/11/30 14:34:15 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/param.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "utils.h"
#include "builtin.h"

int		sh_launch(char **args, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	/* printf("ppid = [%d]\n", pid); */
	if (pid == 0) // 子プロセス
	{
		if (execve(args[0], args, env) == -1)
			printf("shell: %s: %s\n",strerror(errno), args[0]);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)	//fork でエラー
		perror("minish");
	else //親プロセス
	{
		wait(&status);//子プロセスが実行し終わるまで待つ
	}
	return (1);
}

int		sh_execute(char **args, char **env, int fd)
{
	if (args[0] == NULL)
	{
		return (1);
	}
	if (ft_strncmp_ex(args[0], "cd", 3) == 0)
	{
		return (exec_cd(args, env));
	}
	if (ft_strncmp_ex(args[0], "pwd", 4) == 0)
	{
		return (exec_pwd(fd));
	}
	if (ft_strncmp_ex(args[0], "env", 4) == 0)
	{
		return (exec_env(args, env, fd));
	}
	if (ft_strncmp(args[0], "exit", 5) == 0)
	{
		exec_exit(args);
	}
	return (sh_launch(args, env));
}
