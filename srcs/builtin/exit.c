/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:52:47 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/25 19:50:09 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "minishell.h"
#include "libft.h"
#include "utils.h"
#include "utils_stdlib.h"
#include "env_config.h"

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

static int	is_numeric(const char *arg)
{
	int i;
	int sign;

	i = 0;
	sign = 1;
	if ((arg[i] == '-' || arg[i] == '+'))
	{
		sign = (arg[i] == '-') ? -1 : 1;
		i++;
	}
	if (arg[i] == '\0')
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (sign > 0 && ft_strlen(arg) >= 19 && ft_atol(arg) < 0)
		return (0);
	else if (sign < 0 && ft_strlen(arg) >= 19 && ft_atol(arg) > 0)
		return (0);
	return (1);
}

void		exec_exit(char **args)
{
	unsigned int	status;
	int				i;
	char			*arg;

	status = EXIT_SUCCESS;
	i = array_size(args);
	ft_putstr_fd("exit\n", 2);
	arg = args[1] != NULL ? ft_strtrim(args[1], COMMAND_SEPARAT_SPACES) : NULL;
	if (i == 2 && is_numeric(arg))
	{
		status = (unsigned char)ft_atol(arg);
	}
	else if (i == 2)
	{
		status = error_handle("exit", args[1], NUMERIC_ARG, EXIT_RANGE);
	}
	else if (i > 2 && is_numeric(arg))
		status = error_handle("exit", NULL, MANY_ARG, EXIT_FAILURE);
	else if (i > 2)
		status = error_handle("exit", args[1], NUMERIC_ARG, EXIT_RANGE);
	if (arg != NULL)
		free(arg);
	finalize_env_list();
	minishell_exit(status);
}
