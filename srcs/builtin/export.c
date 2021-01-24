/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:45:42 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/24 10:41:55 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "minishell.h"
#include "libft.h"
#include "utils.h"
#include "utils_string.h"
#include "env_list.h"
#include "env_show.h"
#include "msutils_env_param.h"

static int	search_equal(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int			exec_export(char **args)
{
	int		i;
	int		ret_status;
	char	*arg;

	ret_status = 0;
	if (args[1] == NULL)
		show_export_list();
	i = 0;
	while (args[++i])
	{
		if ((!is_invalid_env_name(args[i])))
		{
			arg = ft_join(ft_strdup(args[i]), '\'');
			arg = ft_strjoin_free(ft_strdup("`"), arg);
			ret_status = error_handle("export", arg, INVAILD_ARG, 1);
			free(arg);
		}
		else if (search_equal(args[i]) == 1)
			set_env_value(args[i]);
		else if (get_env_value(args[i]) == NULL)
			set_env_value(args[i]);
	}
	return (ret_status);
}
