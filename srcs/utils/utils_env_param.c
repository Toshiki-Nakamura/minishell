/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:32:51 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 00:33:26 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env_list.h"
#include "utils_string_operation.h"

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
	while (is_printable(*p, " <>|;&"))//環境変数の終端を定義する
	{
		param_len++;
		p++;
	}
	total_len = param_len ? p - cmd : 0;
	return (total_len);
}

char		*replace_env_param(const char *cmd)
{
	const char	*p;
	char		quote;
	int			len;
	char		*env_key;

	p = cmd;
	quote = 0;
	while (*p != 0)
	{
		if (!quote && ((*p == '"') || (*p == '\'')))
			quote = *p;
		else if (quote && (*p == quote))
			quote = 0;
		else if (!quote && (*p == '$'))
		{
			if (!(len = get_envparam_length(p)))
				return (NULL);
			if (!(env_key = malloc(len)))
				return (NULL);
			ft_strlcpy(env_key, (p + 1), len);
			return (replace_word(cmd, (p - cmd), len, get_env_value(env_key)));
		}
		p++;
	}
	return (NULL);
}
