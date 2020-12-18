/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:52:47 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/15 23:19:22 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"

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

int		error_handle(char *cmd, char *arg, char *msg, int exitcode)
{
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(arg, 2);
	ft_putendl_fd(msg, 2);
	return (exitcode);
}

void		exec_exit(char **args)
{
	unsigned int	status;
	int				i;

	status = 0;
	i = 0;
	while (args[i])
		i++;
	ft_putstr_fd("exit\n", 1);
	if (i == 1)
		exit(status);
	if (i == 2 && is_numeric(args[1]))
	{
		status = ft_atoi(args[1]);// unsigned int
	}
	else if (i == 2)
	{
		status = error_handle("exit", args[1], ": numeric argument required", 255);
	}
	else if (i > 2 && is_numeric(args[1]))
		status = error_handle("exit", NULL, "too many arguments", 1);
	else if (i > 2)
		status = error_handle("exit", args[1], ": numeric argument required", 255);
	exit(status); //引数によって終了ステータスを変更しなければならない
}
