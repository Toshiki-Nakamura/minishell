/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:32:51 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 12:48:43 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env_list.h"
#include "utils_string_operation.h"

static char	*find_invalid_envparam_head(char *cmd)
{
	char	*p;
	char	quote;

	p = cmd;
	quote = 0;
	while (*p != 0)
	{
		if (!quote && ((*p == '"') || (*p == '\'')))
			quote = *p;
		else if (quote && (*p == quote))
			quote = 0;
		else if (!quote && (*p == '$'))
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
	p++;
	while (is_printable(*p, " <>|;&"))
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
		return (0);
	ft_strlcpy(env_key, (p + 1), len);
	ret_cmd = replace_word(*cmd, (p - *cmd), len, get_env_value(env_key));
	free(env_key);
	free(*cmd);
	*cmd = ret_cmd;
	if (!replace_env_param(cmd))
		return (0);
	return (1);
}