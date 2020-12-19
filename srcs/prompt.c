/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/19 13:19:00 by tnakamur         ###   ########.fr       */
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
	if (ret == -1)
		exit(0);
}

static void	get_cmd_line(char **line, char c)
{
	char	buf;
	int		ret;

	if (*line == NULL)
		*line = ft_strdup("");
	while ((ret = read(0, &buf, 1)))
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
		*line = ft_join(*line, buf);
	}
	if (c == '\n' && ret == 0 && ft_strcmp(*line, "\0") == 0)
		*line = ft_strjoin_free(*line, ft_strdup("exit"));
	else if (c =='\n' && !ret)
	{
		write(1, "  \b\b", 4);
		get_cmd_line(line, c);
	}
}

void		get_quote_mode(char **line, char quote)
{
	char	*line_next;

	*line = ft_join(*line, '\n');
	ft_putstr_fd("> ", 2);
	line_next = NULL;
	get_cmd_line(&line_next, quote);
	*line = ft_strjoin_free(*line, line_next);
	#if 0
	char	*tmp;
	replace_env_param(line); /* $変数置換 */
	tmp = *line;
	*line = remove_quote(*line);
	free(tmp);
	#endif
}

//echo '"$HOME ''$HOME''" 
//>'

void		check_quote(char **line)
{
	int		quote;
	char	*new;
	int		idx;

	quote = 0;
	idx = 0;
	new = parse_line(*line, &quote, &idx);// " ' を削ぎ落とすのは一番最後
	free(*line);
	*line = new;
	if (quote <= 2)
		return ;
	get_quote_mode(line, quote);
}

void		input_prompt(int *status)
{
	int		fd;
	char	*line;
	char	*new;

	fd = 1;
	line = NULL;
	ft_putstr_fd("\033[32mshell$> \033[0m", 1);
	get_cmd_line(&line, '\n'); // !!! wait return !!!
	check_quote(&line);
	replace_env_param(&line); /* $変数置換 */
	new = remove_quote(line); /* クォーテーション除去 */
	if (line != NULL)
		free(line);
	line = new;
	*status = exec_command_line(line);
	if (line != NULL)
		free(line);
}
