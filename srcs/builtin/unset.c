/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:54:19 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/08 18:04:34 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_list.h"

int			exec_unset(char **args)
{
	int i;

	i = 1;
	while (args[i])
	{
		if (!ft_isalpha(args[i][0]) && args[i][0] != '_' && args[i][0] != '$')
		{
			ft_putstr_fd("bash: unset: `", 2);
			ft_putstr_fd(args[i], 2);
			ft_putendl_fd("': not a valid identifier", 2);
		}
		else if (args[i][0] != '$')
			remove_env_value(args[i]);
		i++;
	}
	return (1);
}
