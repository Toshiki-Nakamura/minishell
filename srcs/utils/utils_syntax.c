/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:52:57 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/07 00:06:59 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_quote.h"
#include "executor.h"
#include "minishell.h"
#include "utils.h"
#include "libft.h"
#include <unistd.h>
#include "utils_string.h"
#include "utils_syntax.h"

int		is_token(int c)
{
	if (c == '|' || c == ';')
		return (1);
	return (0);
}

int		invalid_syntax(const char *str)
{
	int		cmd;
	char	*tmp;

	cmd = 0;
	tmp = (char *)str;
	while (*tmp == ' ' || *tmp == '\t')
		tmp++;
	if (is_token(*tmp))
		return (*tmp);
	while (*tmp)
	{
		if (is_quote(*tmp))
			tmp = skip_to_next_quote(tmp);
		if (*tmp != ' ' && *tmp != '\t' && !is_token(*tmp))
			cmd = 1;
		if (is_token(*tmp) && cmd)
			cmd = 0;
		else if (is_token(*tmp) && !cmd)
			return (*tmp);
		tmp++;
	}
	return (0);
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
		return (1);
	return (0);
}

static int	only_space(char *str)
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
		if (ret && buf == '\n' && (only_space(*line) || \
			(!invalid_syntax(*line) && last_word(*line, '|'))))
			ft_putstr_fd("> ", 2);
		else if (ret && buf == '\n')
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

int		syntax_error(char *msg, char token, int exitcode)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	write(2, " `", 2);
	ft_putchar_fd(token, 2);
	write(2, "'\n", 2);
	return (exitcode);
}

char		*check_token(char *line, char token)
{
	char *next;

	next = NULL;
	if ((token = invalid_syntax(line)))
	{
		set_exit_code(syntax_error(SYNTAX_ERROR, token, 258));
		return (free_set(&line, NULL));
	}
	if (last_word(line, '|') > 0)
	{
		get_next_pipe(&next);
		if (!next)
			return (free_set(&line, NULL));
		line = ft_strjoin_free(line, next);
		if ((token = invalid_syntax(line)) == 0)
			return (line);
		set_exit_code(syntax_error(SYNTAX_ERROR, token, 258));
		return (free_set(&line, NULL));
	}
	return (line);
}
