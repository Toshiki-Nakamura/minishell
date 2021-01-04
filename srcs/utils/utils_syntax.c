/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:52:57 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/04 16:33:59 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_quote.h"
#include "executor.h"
#include "minishell.h"
#include "utils.h"
#include "libft.h"
#include <unistd.h>
#include "utils_string.h"

# define EOF_ERROR  "unexpected end of file"

int		syntax_check(const char *str, char token)
{
	int		cmd;
	char	*tmp;

	cmd = 0;
	tmp = (char *)str;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (*tmp == token)
		return (0);
	while (*tmp)
	{
		if (is_quote(*tmp))
		{
			cmd = 1;
			tmp = skip_to_next_quote(tmp);
		}
		else if (*tmp != ' ' && *tmp != '\t' && *tmp != token)
			cmd = 1;
		if (*tmp == token && cmd)
			cmd = 0;
		else if (*tmp == token && !cmd)
			return (0);
		tmp++;
	}
	return (1);
}

int		last_word(char *str, char token)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	i--;
	while ((str[i] == ' ' || str[i] == '\t') && i > 0)
		i--;
	if (str[i] == token)
		return (0);
	return (1);
}

int		s_space(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	get_next_pipe(char **line)
{
	char	buf;
	int		ret;

	write(2, "not closed pipe\n> ", 19);
	if (*line == NULL)
		*line = ft_strdup("");
	while ((ret = read(0, &buf, 1)) >= 0)
	{
		if ((buf == '\n') && (s_space(*line) || !last_word(*line, '|')))
			ft_putstr_fd("> ", 2);
		else if (buf == '\n')
			break;
		else
			*line = (ret) ? ft_join(*line, buf) : *line;
		if (!ret && !ft_strcmp(*line, ""))
		{
			set_exit_code(error_handle("syntax error", NULL, EOF_ERROR, 258));
			*line = free_set(line, NULL);
			break ;
		}
	}
}

/*
**	syntax error => -1  not close => 0, OK => 1
*/

char		*check_token(char *line, char token)
{
	char *next;

	next = NULL;
	if (syntax_check(line, token) == 0)
	{
		set_exit_code(error_handle(NULL, SYNTAX_ERROR, NULL, 258));
		return (free_set(&line, NULL));
	}
	if (token == '|' && last_word(line, token) == 0)
	{
		get_next_pipe(&next);
		if (!next)
			return (free_set(&line, NULL));
		line = ft_strjoin_free(line, next);
		if (syntax_check(line, token) == 1)
			return (line);
		set_exit_code(error_handle(NULL, SYNTAX_ERROR, NULL, 258));
		return (free_set(&line, NULL));
	}
	return (line);
}
