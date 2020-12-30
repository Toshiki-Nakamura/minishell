/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/30 16:51:57 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_string.h"
#include "cmd_manager.h"
#include "utils_quote.h"
#include "utils_env_param.h"
#include <stdio.h>

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
	while ((ret = read(0, &buf, 1)) >= 0)
	{
		if (c != '\n' && buf == '\n')
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
		else if (!ret)
			break;
		// else if (c =='\n' && !ret)
		// 	write(2, "  \b\b", 4);
		*line = (ret) ? ft_join(*line, buf) : *line;
	}
	// if (c == '\n' && ret == 0 && ft_strcmp(*line, "\0") == 0)
	// 	*line = ft_strjoin_free(*line, ft_strdup("exit"));
	// else if (c =='\n' && !ret)
	// {
	// 	write(2, "  \b\b", 4);
	// 	get_cmd_line(line, c);
	// }
}

void		get_quote_mode(char **line, char quote)
{
	char	*line_next;

	*line = ft_join(*line, '\n');
	ft_putstr_fd("> ", 2);
	line_next = NULL;
	get_cmd_line(&line_next, quote);
	*line = ft_strjoin_free(*line, line_next);
}

//echo '"$HOME ''$HOME''"
//>'

void		check_quote(char **line)
{
	int		quote;
	// char	*new;

	quote = 0;
	parse_line(*line, &quote);// " ' を削ぎ落とすのは一番最後
	// free(*line);
	// *line = new;
	if (quote <= 2)
		return ;
	get_quote_mode(line, quote);
}

void		input_prompt(void)
{
	int		fd;
	char	*line;

	fd = 1;
	line = NULL;
	ft_putstr_fd("\033[32mshell$> \033[0m", 1);
	get_cmd_line(&line, '\n'); // !!! wait return !!!
	check_quote(&line);
	replace_env_param(&line); /* $変数置換 */
	//new = remove_quote(line); /* クォーテーション除去 */
	exec_one_line(line);
	if (line != NULL)
		free(line);
}
