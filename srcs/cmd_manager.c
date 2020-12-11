/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:50 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/11 21:51:37 by tnakamur         ###   ########.fr       */
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
	char	**pipe_list;
	int		i;
	int		ret_status;
	char	**cmd_list;

	ret_status = 1;
	pipe_list = ft_split(line, '|'); //本来はcmd_managerを通した後。
	i = 0;
	while (pipe_list[i])
		i++;
	cmd_list = NULL;
	if (i == 1)
	{
		cmd_list = ft_split(pipe_list[0], ' ');
		if (is_builtin(cmd_list[0])) // 単体かつbuiltin(cd, echo, etc..)
			ret_status = exec_command(pipe_list[0]);
	}
	if (i >= 2 || (i == 1 && !is_builtin(cmd_list[0]))) // pipeコマンド or 単体execve
	{
		ret_status = fork_exec_commands(i, pipe_list);
	}

	if (pipe_list != NULL)
		array_free(pipe_list);
	if (cmd_list != NULL)
		array_free(cmd_list);
	return (ret_status);
}
