/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:46:54 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/14 14:57:34 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/param.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "utils_string.h"
#include "utils.h"
#include "builtin.h"
#include "env_list_base.h"
#include "env_list.h"
#include "inout.h"

int		is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (1);
	if (ft_cmp_ignore_case(cmd, "cd", 3) == 0)
		return (1);
	if (ft_cmp_ignore_case(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_cmp_ignore_case(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0) //完全一致で動作
		return (1);
	if (ft_cmp_ignore_case(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0) //完全一致で動作
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0) //完全一致で動作
		return (1);
	return (0);
}

int		sh_execute(char **args, char **env, int fd)
{
	if (args[0] == NULL)
		return (1);
	if (ft_strncmp(args[0], "cd", 3) == 0)
		return (exec_cd(args, env));
	else if (ft_cmp_ignore_case(args[0], "cd", 3) == 0)
		return (1);
	if (ft_cmp_ignore_case(args[0], "pwd", 4) == 0)
		return (exec_pwd(fd));
	if (ft_cmp_ignore_case(args[0], "env", 4) == 0)
		return (exec_env(args, env, fd));
	if (ft_strncmp(args[0], "exit", 5) == 0)
		exec_exit(args);
	if (ft_cmp_ignore_case(args[0], "echo", 5) == 0)
		return (exec_echo(args, fd));
	if (ft_strncmp(args[0], "unset", 6) == 0)
		return (exec_unset(args));
	if (ft_strncmp(args[0], "export", 7) == 0)
		return (exec_export(args, fd));
	exec_execve(args, env, fd);
	return (1);
}

int			exec_command(char *cmd)
{
	char	**cmd_list;
	int		ret_value;

	ret_value = -1;
#if 0
	//"> filename" があった場合は下記コマンドを実行して出力fdを切り替える
	int fd_std_out;
	int fd_std_in;
	if ((-1 == (fd_std_in = set_redirect_input("hoge.txt")))
		||
		(-1 == (fd_std_out = set_redirect_output("fuga.txt", 0))))
	{
		array_free(cmd_list);
		return (ret_value);
	}
#endif
	cmd_list = ft_split(cmd, ' ');
	ret_value = sh_execute(cmd_list, get_env_param(), 1);

	//undo_redirect_fd(fd_std_in, fd_std_out); //これはプロンプト表示のために毎回戻す

	if (cmd_list != NULL)
		array_free(cmd_list);
	if (ret_value == -1)
		ft_putendl_fd(strerror(errno), 2);
	return (ret_value);
}
