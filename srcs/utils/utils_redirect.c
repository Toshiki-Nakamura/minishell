/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:28:43 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 12:06:10 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "utils_string_operation.h"
#include "utils_string.h"

int		get_redirect_length(const char *cmd)
{
	const char	*p;
	int			total_len;
	int			file_len;

	p = cmd;
	total_len = 0;
	file_len = 0;
	if ((p[0] != '<') && (p[0] != '>'))
		return (0);
	if ((p[0] == '>') && (p[1] == '>') && (is_printable(p[2], "<>")))
		p += 2;
	else if (((p[0] == '>') || (p[0] == '<')) && (is_printable(p[1], "<>")))
		p += 1;
	else
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

int		separate_redirect_word(char **cmd, char **word)
{
	char	*p;
	char	quote;
	int		len;
	char	*ret_cmd;

	p = *cmd;
	quote = 0;
	while (*p != '\0')
	{
		if (!quote && ((*p == '"') || (*p == '\'')))
			quote = *p;
		else if (quote && (*p == quote))
			quote = 0;
		else if (!quote && ((*p == '<') || (*p == '>')))
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
