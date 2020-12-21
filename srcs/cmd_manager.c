/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:50 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/21 14:17:03 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "executor.h"
#include "pipe_executor.h"
#include "env_list_base.h"

void	exec_command_line(const char *line)
{
	int		i;
	char	**pipe_list;
	char	**cmd_list;

	i = 0;
	pipe_list = ft_split(line, '|');
	while (pipe_list[i])
		i++;
	if (i == 1)
	{
		cmd_list = ft_split(pipe_list[0], ' ');
		if (is_builtin(cmd_list[0])) // 単体かつbuiltin(cd, echo, etc..)
			set_exit_code(exec_command(pipe_list[0]));
		else
			set_exit_code(fork_exec_commands(i, pipe_list));
		if (cmd_list != NULL)
			array_free(cmd_list);
	}
	else if (2 <= i)// pipeコマンド
		set_exit_code(fork_exec_commands(i, pipe_list));
	if (pipe_list != NULL)
		array_free(pipe_list);
	return ;
}
