/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/08 17:32:34 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "utils_string.h"
#include "executor.h"

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
	*args = ft_split(*line, ' ');
	*status = sh_execute(*args, *env, fd, 0);
	if (*args != NULL)
		array_free(*args);
	if (*line != NULL)
		free(*line);
}
