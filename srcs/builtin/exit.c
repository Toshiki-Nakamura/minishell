/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:52:47 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/24 19:19:08 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"
#include "env_list_base.h"
#include "utils.h"
#include "minishell.h"

static int is_numeric(const char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (i == 0 && (arg[i] == '-' || arg[i] == '+'))
			;
		else if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

void		exec_exit(char **args)
{
	unsigned int	status;
	int				i;

	status = EXIT_SUCCESS;
	i = 0;
	while (args[i])
		i++;
	ft_putstr_fd("exit\n", 1);
	if (i == 2 && is_numeric(args[1]))
	{
		status = (unsigned char)ft_atoi(args[1]);
	}
	else if (i == 2)
	{
		status = error_handle("exit", args[1], NUMERIC_ARG, EXIT_RANGE);
	}
	else if (i > 2 && is_numeric(args[1]))
		status = error_handle("exit", NULL, MANY_ARG, EXIT_FAILURE);
	else if (i > 2)
		status = error_handle("exit", args[1], NUMERIC_ARG, EXIT_RANGE);
	finalize_env_list();
	// system("leaks minishell");
	exit(status);
}
