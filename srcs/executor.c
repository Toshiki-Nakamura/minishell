/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:46:54 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/27 01:01:21 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/param.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"
#include "utils_string.h"
#include "utils.h"
#include "utils_redirect.h"
#include "builtin.h"
#include "env_list_base.h"
#include "env_list.h"
#include "env_info.h"
#include "redirect.h"
#include "executor.h"
#include "utils_quote.h"

void		set_exit_code(int code)
{
	char *s;
	s = ft_itoa(code);
	char *exit_code = ft_strjoin("?=", s);
	free(s);
	set_env_value(exit_code);
	free(exit_code);
}

int			is_builtin(char *cmd)
{
	if (cmd == NULL)
		return (1);
	if (ft_strcmp(cmd, "cd") == 0) //大文字はexecveで実行
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0) //大文字はexecveで実行
		return (1);
	if (ft_cmp_ignore_case(cmd, "env", 4) == 0) // return 0にするか検討中
		return (1);
	if (ft_strcmp(cmd, "exit") == 0)
		return (1);
	if (ft_strcmp(cmd, "echo") == 0) //大文字はexecveで実行
		return (1);
	if (ft_strcmp(cmd, "unset") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0)
		return (1);
	return (0);
}

int			sh_execute(char **args, char **env, int fd)
{
	if (args[0] == NULL)
		return (ft_atoi(g_env_question));
	if (ft_strcmp(args[0], "cd") == 0)
		return (exec_cd(args, env));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (exec_pwd(fd));
	if (ft_cmp_ignore_case(args[0], "env", 4) == 0)
		return (exec_env(args, env, fd));
	if (ft_strcmp(args[0], "exit") == 0)
		exec_exit(args);
	if (ft_strcmp(args[0], "echo") == 0)
		return (exec_echo(args, fd));
	if (ft_strcmp(args[0], "unset") == 0)
		return (exec_unset(args));
	if (ft_strcmp(args[0], "export") == 0)
		return (exec_export(args, fd));
	return (exec_execve(args, env, fd));
}

static int	exec_simple_command(char *cmd)
{
	char	**cmd_list;
	int		ret_value;

	cmd_list = util_split(cmd, ' ');
	iter_remove_quote(cmd_list);
	ret_value = sh_execute(cmd_list, get_env_param(), 1);
	if (cmd_list != NULL)
		array_free(cmd_list);
	return (ret_value);
}

int			exec_command(char *cmd)
{
	int		ret_value;
	int 	fd_std_in;
	int 	fd_std_out;
	char 	*redirect;
	char 	*str;
	t_redirection	type;

	str = ft_strdup(cmd);
	fd_std_in = 0;
	fd_std_out = 1;
	// TODO: echo hoge ><a.txt >b.txt の場合、 syntax error near unexpected token `<'で終了すべき
	// TODO: echo '---<a.out>---' がリダイレクトとして認識されてしまう。promptで''を落としているのが原因
	while (separate_redirect_word(&str, &redirect))
	{
		undo_redirect_fd(fd_std_in, fd_std_out);
		separate_redirect_info(&redirect, &type);
		if ((type == REDIRECT_INPUT)
			&& (-1 == (fd_std_in = set_redirect_input(redirect))))
			return (-1);
		else if ((type == REDIRECT_APPEND)
			&& (-1 == (fd_std_out = set_redirect_output(redirect, 0))))
			return (-1);
		else if ((type == REDIRECT_OVERRIDE)
			&& (-1 == (fd_std_out = set_redirect_output(redirect, 1))))
			return (-1);
		free(redirect);
	}
	ret_value = exec_simple_command(str);
	free(str);
	undo_redirect_fd(fd_std_in, fd_std_out); //これはプロンプト表示のために毎回戻す
	if (ret_value == -1)
		ft_putendl_fd(strerror(errno), 2);
	return (ret_value);
}
