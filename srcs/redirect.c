/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:03:44 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/26 11:41:32 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "utils.h"
#include "utils_is.h"
#include "utils_string_operation.h"
#include "utils_quote.h"

static t_redirect	g_redirect_marks[] = {
	{"<", REDIRECT_INPUT},
	{">>", REDIRECT_APPEND},
	{">", REDIRECT_OVERRIDE},
	{NULL, REDIRECT_NUM}
};

const char			*skip_redirect_mark(const char *redirect,
					t_redirect_type *type)
{
	size_t		length;
	int			i;

	*type = REDIRECT_NUM;
	i = 0;
	while (g_redirect_marks[i].mark)
	{
		length = ft_strlen(g_redirect_marks[i].mark);
		if (0 == ft_strncmp(redirect, g_redirect_marks[i].mark, length))
		{
			*type = g_redirect_marks[i].type;
			return (redirect + length);
		}
		i++;
	}
	return (NULL);
}

int					get_redirect_length(const char *redirect)
{
	const char		*p;
	int				total_len;
	t_redirect_type	type;

	if (!(p = skip_redirect_mark(redirect, &type)))
		return (0);
	total_len = p - redirect;
	while (*p == ' ')
		p++;
	while (*p && is_printable(*p, IS_NOT_REDIRECT_WORD))
	{
		p++;
		total_len = p - redirect;
	}
	return (total_len);
}

void				separate_redirect_info(char **redirect,
				t_redirect_type *type)
{
	const char	*p;
	int			total_len;
	int			file_len;
	char		*ret;

	total_len = 0;
	file_len = 0;
	if (!(p = skip_redirect_mark(*redirect, type)))
		return ;
	while (*p == ' ')
		p++;
	while (is_printable(p[file_len], IS_NOT_REDIRECT_WORD))
	{
		file_len++;
	}
	if (!(ret = malloc(file_len + 1)))
		error_force_exit(MALLOC_ERROR);
	ft_strlcpy(ret, p, file_len + 1);
	free(*redirect);
	*redirect = ret;
}

int					separate_redirect_word(char **cmd, char **word)
{
	char	*p;
	int		len;
	char	*ret_cmd;

	p = *cmd;
	while (*p != '\0')
	{
		if ((*p == '"') || (*p == '\''))
			p = skip_to_next_quote(p);
		else if (0 < (len = get_redirect_length(p)))
		{
			if (!(ret_cmd = extract_word(*cmd, p - *cmd, len, word)))
				error_force_exit(MALLOC_ERROR);
			free(*cmd);
			*cmd = ret_cmd;
			return (1);
		}
		p++;
	}
	return (0);
}
