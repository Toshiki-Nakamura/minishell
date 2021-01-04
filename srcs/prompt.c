/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/04 15:14:51 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"
#include "libft.h"
#include "utils_string.h"
#include "utils_quote.h"
#include "utils_env_param.h"
#include "utils_string_operation.h"
#include "prompt.h"
#include "cmd_manager.h"
#include "utils_syntax.h"
#include "executor.h"
#include "utils.h"

void	get_quote_line(char **line)
{
	char	buf;
	int		ret;
	int		flag;

	flag = 0;
	while ((ret = read(0, &buf, 1)))
	{
		if (buf == '\n' && flag)
			ft_putstr_fd("> ", 2);
		if (buf == flag)
		{
			*line = ft_join(*line, buf);
			get_quote_line(line);
			break;
		}
		if (!flag && is_quote(buf))
			flag = buf;
		if (buf == '\n' && !flag)
			break;
		*line = ft_join(*line, buf);
	}
}

static void	get_cmd_line(char **line, char c)
{
	char	buf;
	int		ret;

	if (*line == NULL)
		*line = ft_strdup("");
	while ((ret = read(0, &buf, 1)) >= var)
	{
		if (c != '\n' && buf == '\n' && ret)
			ft_putstr_fd("> ", 2);
		if (c != '\n' && c == buf)
		{
			*line = ft_join(*line, buf);
			get_quote_line(line);
			break ;
		}
		else if (buf == c)
			break;
		if (c == '\n' && ret == 0 && ft_strcmp(*line, "\0") == 0)
		{
			*line = ft_strjoin_free(*line, ft_strdup("exit"));
			break ;
		}
		// else if (!ret)
		// 	break;
		/* *line = (!ret) ? eof(*line, c, &ret) : ft_join(*line, buf); */
		*line = (ret) ? ft_join(*line, buf) : *line;
	}
}

void		get_quote_mode(char **line, int quote)
{
	char	*line_next;

	*line = ft_join(*line, '\n');
	ft_putstr_fd("> ", 2);
	line_next = NULL;
	get_cmd_line(&line_next, quote);
	if (line_next == NULL)
	{
		free_set(line, NULL);
		return ;
	}
	*line = ft_strjoin_free(*line, line_next);
	quote = 0;
	parse_line(*line, &quote);
	if (quote > 2)
		free_set(line, NULL);
}

//echo '"$HOME ''$HOME''"
//>'

void		check_quote(char **line)
{
	int		quote;

	quote = 0;
	parse_line(*line, &quote);// " ' を削ぎ落とすのは一番最後
	if (quote <= 2)
		return ;
	get_quote_mode(line, quote);
}

void		input_prompt(void)
{
	char	*line;

	line = NULL;
	ft_putstr_fd("\033[32mshell$> \033[0m", 2);
	get_cmd_line(&line, '\n'); // !!! wait return !!!
	check_quote(&line);
	if (!line)
		return ;
	replace_env_param(&line);
	remove_comment(&line);
	exec_one_line(line);
	if (line != NULL)
		free(line);
}
