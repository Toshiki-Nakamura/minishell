/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:50 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/30 16:54:21 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "executor.h"
#include "pipe_executor.h"
#include "env_list_base.h"
#include "utils_quote.h"
#include "utils_string.h"
#include "utils_string_operation.h"

static void		exec_command_line(const char *line)
{
	int		i;
	char	**pipe_list;
	char	**cmd_list;

	i = 0;
	pipe_list = util_split(line, '|');
	while (pipe_list[i])
		i++;
	if (i == 1)
	{
		cmd_list = util_split(pipe_list[0], ' ');
		iter_remove_quote(cmd_list);
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

void			exec_one_line(const char *line)
{
	char	*str;
	// ;や#を含む1行を実行する
	str = ft_strdup(line);
	remove_comment(&str);
	//TODO: ;がきたら分割する
	exec_command_line(str);
	free(str);
}
