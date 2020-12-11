/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:45:42 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/11 18:54:18 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"
#include "env_show.h"

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

	(void)args;
	(void)fd;
	if (args[1] == NULL)
		show_export_list();
	i = 0;
	while (args[++i])
	{
		if (!ft_isalpha(args[i][0]) && args[i][0] != '_')
		{
			ft_putstr_fd("export: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
		}
		else if (search_equal(args[i]) == 1)
			set_env_value(args[i]);
		else if (get_env_value(args[i]) == NULL)
			set_env_value(args[i]);
	}
	return (1);
}
