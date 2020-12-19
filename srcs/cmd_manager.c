/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:50 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/19 13:54:48 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "executor.h"
#include "pipe_executor.h"
#include "env_list_base.h"

int		exec_command_line(const char *line)
{
	int		ret_status;
	int		i;
	char	**pipe_list;
	char	**cmd_list;

	ret_status = g_old_status;
	i = 0;
	pipe_list = ft_split(line, '|');
	while (pipe_list[i])
		i++;
	if (i == 1)
	{
		cmd_list = ft_split(pipe_list[0], ' ');
		if (is_builtin(cmd_list[0])) // 単体かつbuiltin(cd, echo, etc..)
			ret_status = exec_command(pipe_list[0]);
		else
			ret_status = fork_exec_commands(i, pipe_list);
		if (cmd_list != NULL)
			array_free(cmd_list);
	}
	else if (2 <= i)// pipeコマンド
		ret_status = fork_exec_commands(i, pipe_list);
	if (pipe_list != NULL)
		array_free(pipe_list);
	return (ret_status);
}
