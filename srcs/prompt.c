/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/09 01:10:38 by tnakamur         ###   ########.fr       */
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

void		input_prompt(char **line, char ***args, char ***env, int *status)
{
	int fd;

	fd = 1;
	ft_putstr_fd("\033[32mshell$> \033[0m", 1);
	*line = get_cmd_line(); // !!! wait return !!!
	// ;	複数コマンドのパース
	// |	パイプ
	// ' "	クォーテーション
	// > >>	リダイレクト fd
	(void)env;
	(void)args;

	//本来はcmd_managerを通した後。
	char **pipe_list;
	pipe_list = ft_split(*line, '|');
	int i = 0;
	while (pipe_list[i])
		i++;
	if (i == 1)
	{
#if 1
		char	**cmd_list;
		cmd_list = ft_split(pipe_list[0], ' ');
		if (pipe_list != NULL)
			array_free(pipe_list);
		*status = sh_execute(cmd_list, *env, fd, 0);
		if (cmd_list != NULL)
			array_free(cmd_list);
#else//こちらにしたい。
		*status = exec_command(pipe_list);
#endif
	}
	else if (i >= 2)
		*status = exec_pipe_list(i, pipe_list);
	//printf("finish input_prompt ret=%d\n", *status);
	if (*args != NULL)
		array_free(*args);
	if (*line != NULL)
		free(*line);
}
