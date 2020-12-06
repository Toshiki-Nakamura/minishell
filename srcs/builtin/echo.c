/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:42:42 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/06 17:43:35 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"

static int	is_env(char *str)
{
	if (str[0] == '$')
	{
		if (str[1] != '\0' && str[1] != '$')
			return (1);
		else if (str[1] == '$')
			return (-1);
	}
	return (0);
}

int			exec_echo(char **args, int fd)
{
	int	i;

	i = 1;
	if (args[1] == NULL)
		ft_putstr_fd("", fd);
	if (args[1] && ft_strncmp(args[1], "-n", 3) == 0)
		i++;
	while (args[i])
	{
		if (!is_env(args[i]))
			ft_putstr_fd(args[i], fd);
		else
			ft_putstr_fd((char *)get_env_value(args[i] + 1), fd);
		i++;
		if (args[i] != NULL)
			write(fd, " ", 1);
	}
	if (!args[1] || ft_strncmp(args[1], "-n", 3) != 0)
		write(fd, "\n", 1);
	return (1);
}
