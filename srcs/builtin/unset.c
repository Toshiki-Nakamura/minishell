/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:54:19 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/24 18:46:15 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"
#include "utils.h"
#include "minishell.h"
#include "utils_env_param.h"

int			exec_unset(char **args)
{
	int i;
	int ret_status;

	i = 1;
	ret_status = 0;
	while (args[i])
	{
		if (!is_invalid_env_name(args[i]))
		{
			ret_status = error_handle("unset", args[i], INVAILD_ARG, 1);
		}
		else if (args[i][0] != '$')
			remove_env_value(args[i]);
		i++;
	}
	return (ret_status);
}
