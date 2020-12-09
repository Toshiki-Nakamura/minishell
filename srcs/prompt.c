/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/09 16:06:55 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "utils.h"
#include "utils_string.h"
#include "executor.h"
#include "pipe_executor.h"
#include "env_list.h"
#include "env_list_base.h"

static char	*get_cmd_line(void)
{
	char	*line;
	char	buf;
	int		ret;

	line = ft_strdup("");
	while ((ret = read(0, &buf, 1)))
	{
		if (buf == '\n')
			break ;
		line = ft_join(line, buf);
	}
	if (ret == -1)
		exit(0);
	return (line);
}

void		input_prompt(int *status)
{
	int		fd;
	char	**pipe_list;
	int		i;
	char	*line;

	fd = 1;
	ft_putstr_fd("\033[32mshell$> \033[0m", 1);
	line = get_cmd_line(); // !!! wait return !!!
	// ;	複数コマンドのパース
	// |	パイプ
	// ' "	クォーテーション
	// > >>	リダイレクト fd
	pipe_list = ft_split(line, '|'); //本来はcmd_managerを通した後。
	if (line != NULL)
		free(line);
	i = 0;
	while (pipe_list[i])
		i++;
	if (i == 1)
	{
#if 1
		char	**cmd_list;
		cmd_list = ft_split(pipe_list[0], ' ');
		*status = sh_execute(cmd_list, get_env_param(), fd, 0);
		if (cmd_list != NULL)
			array_free(cmd_list);
#else//こちらにしたい。
		*status = exec_command(pipe_list[0]);
#endif
	}
	else if (i >= 2)
		*status = fork_exec_commands(i, pipe_list);
	if (pipe_list != NULL)
		array_free(pipe_list);
}
