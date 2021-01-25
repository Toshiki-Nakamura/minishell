/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:46:54 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/24 22:30:50 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/param.h>
#include <stdio.h>
#include <string.h>
#include "minishell.h"
#include "libft.h"
#include "utils.h"
#include "utils_string.h"
#include "utils_quote.h"
#include "utils_string_operation.h"
#include "msutils_convert.h"
#include "msutils_redirect.h"
#include "env_list_base.h"
#include "env_list.h"
#include "env_info.h"
#include "redirect.h"
#include "builtin.h"

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

static int	sh_execute(char **args, char **env)
{
	if (args[0] == NULL)
		return (ft_atoi(g_env_question));
	if (ft_strcmp(args[0], "cd") == 0)
		return (exec_cd(args));
	if (ft_strcmp(args[0], "pwd") == 0)
		return (exec_pwd());
	if (ft_cmp_ignore_case(args[0], "env", 4) == 0)
		return (exec_env(args));
	if (ft_strcmp(args[0], "exit") == 0)
		exec_exit(args);
	if (ft_strcmp(args[0], "echo") == 0)
		return (exec_echo(args));
	if (ft_strcmp(args[0], "unset") == 0)
		return (exec_unset(args));
	if (ft_strcmp(args[0], "export") == 0)
		return (exec_export(args));
	return (exec_execve(args, env));
}

static int	exec_simple_command(char *cmd)
{
	char	**cmd_list;
	int		ret_value;

	if (!(cmd_list = util_split(cmd, COMMAND_SEPARAT_SPACES)))
		error_force_exit(MALLOC_ERROR);
	iter_array(cmd_list, &replace_tilde);
	iter_array(cmd_list, &remove_quote);
	ret_value = sh_execute(cmd_list, get_env_param());
	if (cmd_list != NULL)
		array_free(cmd_list);
	return (ret_value);
}

int			exec_command(char *cmd)
{
	int		ret_value;
	char 	*redirect;
	char 	*str;
	t_fd 	fd;
	t_redirect_type	type;

	ret_value = 0;
	str = ft_strdup(cmd);
	init_redirect_fd(&fd);
	while (!ret_value && separate_redirect_word(&str, &redirect))
	{
		separate_redirect_info(&redirect, &type);
		replace_tilde(&redirect);
		remove_quote(&redirect);
		ret_value = set_redirect(redirect, &fd, type);
		free(redirect);
	}
	if (!ret_value)
		ret_value = exec_simple_command(str);
	free(str);
	undo_redirect_fd(fd);
	return (ret_value);
}
