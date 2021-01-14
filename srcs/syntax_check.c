/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 13:24:42 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/14 19:29:11 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minishell.h"
#include "libft.h"
#include "executor.h"
#include "utils.h"
#include "utils_quote.h"
#include "utils_string.h"
#include "utils_syntax.h"

static int	check_quote(const char *line)
{
	int		quote;

	quote = 0;
	while (line[0] != '\0')
	{
		if ((quote = is_quote(line[0])) > 0)
		{
			line = skip_to_next_quote(line);
			if (line[0] == '\0')
			{
				ft_putendl_fd("not closed", 2);
				quote = (quote == 2) ? '\"' : '\'';
				break ;
			}
		}
		line++;
	}
	if (quote <= 2)
		return (1);
	set_exit_code(error_handle(SYNTAX_ERROR, NULL, "quote", 258));
	return (0);
}

static int	check_invalid_operator(const char *line)
{
#if 0
	while (*line != '\0')
	{
		if (ft_strchr(MINISHELL_INVALID_OPERATOR, *line))
			return (0);
		line++;
	}
#else
	(void)line;
#endif
	return (1);
}

static int		check_valid_operator(const char *line)
{
	char token;

	if ((token = parse_syntax(line)))
	{
		set_exit_code(put_syntax_err(SYNTAX_ERROR, token, 258));
		return (0);
	}
	if (check_closed(line, '|') > 0)
	{
		set_exit_code(put_syntax_err(SYNTAX_ERROR, '|', 258));
		return (0);
	}
	return (1);
}

int			check_syntax(const char *line)
{
	if (check_quote(line)
		&& check_invalid_operator(line)
		&& check_valid_operator(line)
		// && check関数を追加してください
	)
	{
		return (1);
	}
	// set_exit_code(error_handle(SYNTAX_ERROR, NULL, "quote", 258));
	return (0);
}


