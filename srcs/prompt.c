/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 20:55:46 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_string.h"
#include "cmd_manager.h"
#include "utils_quote.h"
#include "utils_env_param.h"

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

void		get_quote_mode(char **line, char quote)
{
	char	*line_next;

	*line = ft_join(*line, '\n');
	ft_putstr_fd("> ", 2);
	line_next = get_cmd_line(quote);
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
	ft_putstr_fd("\033[32mshell$> \033[0m", 1);
	line = get_cmd_line('\n'); // !!! wait return !!!
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
