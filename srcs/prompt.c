/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/15 15:09:33 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_string.h"
#include "cmd_manager.h"
#include "utils_quote.h"

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

static char	*get_cmd_line(char c)
{
	char	*line;
	char	buf;
	int		ret;

	line = ft_strdup("");
	while ((ret = read(0, &buf, 1)))
	{
		if (c != '\n' && buf == '\n')
			ft_putstr_fd("> ", 2);
		if (c != '\n' && c == buf)
		{
			line = ft_join(line, buf);
			get_quote_line(&line);// line = ft_strjoin_free(line, get_quote_line());
			break ;
		}
		else if (buf == c)
			break;
		line = ft_join(line, buf);
	}
	if (ret == -1)
		exit(0);
	return (line);
}

void		get_quote_mode(char **line, char quote, int idx)
{
	char	*line_next;
	char	*mode_line;
	char	*tmp;
	int		q;
	int		n_idx;

	q = 0;
	n_idx = 0;
	*line = ft_join(*line, '\n');
	ft_putstr_fd("> ", 2);
	line_next = get_cmd_line(quote);
	*line = ft_strjoin_free(*line, line_next);

	tmp = *line;
	mode_line = clean_line(tmp + idx, &q, &n_idx); /* 後程、$変数挿し込む */
	tmp[idx] = '\0';
	*line = ft_strjoin_free(*line, mode_line);
}

void		check_quote(char **line)
{
	int		quote;
	char	*new;
	int		idx;

	quote = 0;
	idx = 0;
	new = clean_line(*line, &quote, &idx);
	free(*line);
	*line = new;
	if (quote <= 2)
		return ;
	get_quote_mode(line, quote, idx);
}

void		input_prompt(int *status)
{
	int		fd;
	char	*line;

	fd = 1;
	ft_putstr_fd("\033[32mshell$> \033[0m", 1);
	line = get_cmd_line('\n'); // !!! wait return !!!
	check_quote(&line);
	*status = exec_command_line(line);
	if (line != NULL)
		free(line);
}
