/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:50 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/10 12:45:20 by skohraku         ###   ########.fr       */
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

	ret_status = 0;
	// ;	複数コマンドのパース
	// |	パイプ
	// ' "	クォーテーション
	// > >>	リダイレクト fd
	pipe_list = ft_split(line, '|'); //本来はcmd_managerを通した後。
	i = 0;
	while (pipe_list[i])
		i++;
	if (i == 1)
	{
#if 1
		char	**cmd_list;
		cmd_list = ft_split(pipe_list[0], ' ');
		ret_status = sh_execute(cmd_list, get_env_param(), 1, 0);
		if (cmd_list != NULL)
			array_free(cmd_list);
#else//こちらにしたい。
		ret_status = exec_command(pipe_list[0]);
#endif
	}
	else if (i >= 2)
		ret_status = fork_exec_commands(i, pipe_list);
	if (pipe_list != NULL)
		array_free(pipe_list);

	return (ret_status);
}