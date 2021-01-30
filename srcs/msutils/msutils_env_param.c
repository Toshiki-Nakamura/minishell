/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_env_param.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:32:51 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/25 20:05:24 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "utils_string.h"
#include "utils_string_operation.h"
#include "utils_quote.h"
#include "env_list.h"

int			is_invalid_env_name(const char *key)
{
	const char	*p;

	p = key;
	if (!ft_isalpha(*p) && (*p != '_'))
		return (0);
	while (*p && (*p != '='))
	{
		if (!ft_isalnum(*p) && (*p != '_'))
			return (0);
		p++;
	}
	return (1);
}

static char	*find_invalid_envparam_head(char *cmd)
{
	char	*p;
	char	d_quote;

	p = cmd;
	d_quote = 0;
	while (*p != 0)
	{
		if (*p == '\'' && !d_quote)
			p = skip_to_next_quote(p);
		else if (*p == '"')
			d_quote = ~d_quote;
		else if (*p == '$')
			return (p);
		p++;
	}
	return (NULL);
}

int			get_envparam_length(const char *cmd)
{
	const char	*p;
	int			param_len;
	int			total_len;

	p = cmd;
	param_len = 0;
	total_len = 0;
	if (*p != '$')
		return (0);
	if (0 == ft_strncmp(p, "$?", 2))
		return (2);
	p++;
	while (*p && (ft_isalnum(*p) || (*p == '_')))
	{
		param_len++;
		p++;
	}
	total_len = param_len ? p - cmd : 0;
	return (total_len);
}

int			replace_env_param(char **cmd)
{
	char	*p;
	int		len;
	char	*ret_cmd;
	char	*env_key;

	if (!(p = find_invalid_envparam_head(*cmd)))
		return (0);
	if (!(len = get_envparam_length(p)))
		return (0);
	if (!(env_key = malloc(len)))
		error_force_exit(MALLOC_ERROR);
	ft_strlcpy(env_key, (p + 1), len);
	if (!(ret_cmd = replace_word(*cmd, (p - *cmd), len, \
								get_env_value(env_key))))
		error_force_exit(MALLOC_ERROR);
	free(env_key);
	free(*cmd);
	*cmd = ret_cmd;
	if (!replace_env_param(cmd))
		return (0);
	return (1);
}

void		set_exit_code(int code)
{
	char *s;
	char *exit_code;

	s = ft_itoa(code);
	exit_code = ft_strjoin("?=", s);
	free(s);
	set_env_value(exit_code);
	free(exit_code);
}
