/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:28:43 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/21 15:22:49 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "utils_string_operation.h"
#include "utils_string.h"
#include "utils_redirect.h"
#include "utils_quote.h"

const char	*skip_redirect_mark(const char *cmd, t_redirection *type)
{
	const char	*p;

	p = cmd;
	*type = REDIRECT_NONE;
	if ((p[0] == '>') && (p[1] == '>') && (is_printable(p[2], "<>&")))
	{
		*type = REDIRECT_APPEND;
		p += 2;
	}
	else if ((p[0] == '>') && (is_printable(p[1], "<>&")))
	{
		*type = REDIRECT_OVERRIDE;
		p += 1;
	}
	else if ((p[0] == '<') && (is_printable(p[1], "<>&")))
	{
		*type = REDIRECT_INPUT;
		p += 1;
	}
	else
		return (NULL);
	return (p);
}

void		separate_redirect_info(char **cmd, t_redirection *type)
{
	const char	*p;
	int			total_len;
	int			file_len;
	char		*ret;

	total_len = 0;
	file_len = 0;
	if (!(p = skip_redirect_mark(*cmd, type)))
		return ;
	while (*p == ' ')
		p++;
	while (is_printable(p[file_len], " "))
	{
		file_len++;
	}
	if (!(ret = malloc(file_len + 1)))
		return ;
	ft_strlcpy(ret, p, file_len + 1);
	free(*cmd);
	*cmd = ret;
}

int			get_redirect_length(const char *cmd)
{
	const char		*p;
	int				total_len;
	int				file_len;
	t_redirection	type;

	total_len = 0;
	file_len = 0;
	if (!(p = skip_redirect_mark(cmd, &type)))
		return (0);
	while (*p == ' ')
		p++;
	while (is_printable(*p, " "))
	{
		file_len++;
		p++;
	}
	total_len = file_len ? p - cmd : 0;
	return (total_len);
}

int			separate_redirect_word(char **cmd, char **word)
{
	char	*p;
	int		len;
	char	*ret_cmd;

	p = *cmd;
	while (*p != '\0')
	{
		if ((*p == '"') || (*p == '\''))
			p = skip_to_next_quote(p);
		else if ((*p == '<') || (*p == '>'))
		{
			if (!(len = get_redirect_length(p)))
				break ;
			ret_cmd = extract_word(*cmd, p - *cmd, len, word);
			free(*cmd);
			*cmd = ret_cmd;
			return (1);
		}
		p++;
	}
	return (0);
}
