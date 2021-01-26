/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:50 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/26 10:29:11 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft.h"
#include "utils.h"
#include "utils_quote.h"
#include "utils_string.h"
#include "utils_string_operation.h"
#include "msutils_env_param.h"
#include "pipe_executor.h"
#include "executor.h"

static void		exec_command_line(const char *line)
{
	int		i;
	char	**pipe_list;
	char	**cmd_list;

	i = 0;
	if (!(pipe_list = util_split(line, "|")))
		error_force_exit(MALLOC_ERROR);
	while (pipe_list[i])
		i++;
	if (i == 1)
	{
		if (!(cmd_list = util_split(pipe_list[0], COMMAND_SEPARAT_SPACES)))
			error_force_exit(MALLOC_ERROR);
		if (is_builtin(cmd_list[0]))
			set_exit_code(exec_command(pipe_list[0]));
		else
			set_exit_code(fork_exec_commands(pipe_list));
		if (cmd_list != NULL)
			array_free(cmd_list);
	}
	else if (2 <= i)
		set_exit_code(fork_exec_commands(pipe_list));
	if (pipe_list != NULL)
		array_free(pipe_list);
	return ;
}

void			exec_one_line(const char *line)
{
	char	**commands;
	int		i;

	if (!(commands = util_split(line, ";")))
		error_force_exit(MALLOC_ERROR);
	i = 0;
	while (commands[i] != NULL)
	{
		exec_command_line(commands[i]);
		i++;
	}
	if (commands != NULL)
		array_free(commands);
}
