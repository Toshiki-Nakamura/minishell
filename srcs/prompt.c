/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/14 14:43:59 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"
#include "libft.h"
#include "utils_string.h"
#include "utils_env_param.h"
#include "utils_string_operation.h"
#include "prompt.h"
#include "cmd_manager.h"
#include "executor.h"
#include "utils.h"
#include "syntax_check.h"

static void	get_cmd_line(char **line, char c)
{
	char	buf;
	int		ret;

	if (*line == NULL)
		*line = ft_strdup("");
	while ((ret = read(0, &buf, 1)) >= VAR)
	{
		if (buf == c)
			break;
		if (c == '\n' && ret == 0 && ft_strcmp(*line, "\0") == 0)
		{
			// *line = ft_strjoin_free(*line, ft_strdup("exit"));
			free_set(line, ft_strdup("exit"));
			break ;
		}
		else if (ret == 0)
			write(2, "  \b\b", 4);
		*line = (ret) ? ft_join(*line, buf) : *line;
	}
}

void		input_prompt(void)
{
	g_line = NULL;
	ft_putstr_fd("\033[32mshell$> \033[0m", 1);
	get_cmd_line(&g_line, '\n'); // !!! wait return !!!
	if (check_syntax(g_line))
	{
		replace_env_param(&g_line);
		remove_comment(&g_line);
		exec_one_line(g_line);
	}
	if (g_line != NULL)
		free(g_line);
}
