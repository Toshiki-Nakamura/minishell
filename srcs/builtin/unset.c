/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:54:19 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 14:28:03 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include "utils.h"
#include "utils_string.h"
#include "env_list.h"
#include "msutils_env_param.h"

int			exec_unset(char **args)
{
	int		i;
	int		ret_status;
	char	*arg;

	i = 1;
	ret_status = 0;
	while (args[i])
	{
		if (!is_invalid_env_name(args[i]) || ft_strchr(args[i], '='))
		{
			arg = ft_join(ft_strdup(args[i]), '\'');
			arg = ft_strjoin_free(ft_strdup("`"), arg);
			ret_status = error_handle("unset", arg, INVAILD_ARG, 1);
			free(arg);
		}
		else if (args[i][0] != '$')
			remove_env_value(args[i]);
		i++;
	}
	return (ret_status);
}
