/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:52:47 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/18 16:00:40 by skohraku         ###   ########.fr       */
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

#ifdef TEST
static void	minishell_exit(int status)
{
	system("leaks minishell 2> /dev/null");
	exit(status);
}
#else
static void	minishell_exit(int status)
{
	exit(status);
}
#endif

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
	minishell_exit(status);
}
