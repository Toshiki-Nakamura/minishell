/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:45:42 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/22 14:01:06 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"
#include "env_show.h"
#include "utils.h"
#include "minishell.h"

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

int			exec_export(char **args, int fd)
{
	int i;
	int	ret_status;

	(void)args;
	(void)fd;
	ret_status = 0;
	if (args[1] == NULL)
		show_export_list();
	i = 0;
	while (args[++i])
	{
		if (!ft_isalpha(args[i][0]) && args[i][0] != '_')
		{
			ret_status = error_handle("export", args[i], INVAILD_ARG, 1);
		}
		else if (search_equal(args[i]) == 1)
			set_env_value(args[i]);
		else if (get_env_value(args[i]) == NULL)
			set_env_value(args[i]);
	}
	return (ret_status);
}
