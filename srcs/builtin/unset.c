/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:54:19 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/19 12:33:45 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

int			exec_unset(char **args)
{
	int i;
	int ret_status;

	i = 1;
	ret_status = 0;
	while (args[i])
	{
		if (!ft_isalpha(args[i][0]) && args[i][0] != '_' && args[i][0] != '$')
		{
			ft_putstr_fd("bash: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
			ret_status = 1;
		}
		else if (args[i][0] != '$')
			remove_env_value(args[i]);
		i++;
	}
	return (ret_status);
}
