/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 15:24:45 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "utils_string.h"
#include "msutils_env_param.h"
#include "msutils_convert.h"
#include "syntax_check.h"
#include "prompt.h"
#include "cmd_manager.h"

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
