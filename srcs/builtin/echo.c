/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:42:42 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/16 17:26:02 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"


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
		ft_putstr_fd(args[i], fd);
		i++;
		if (args[i] != NULL)
			write(fd, " ", 1);
	}
	if (!args[1] || ft_strncmp(args[1], "-n", 3) != 0)
		write(fd, "\n", 1);
	return (1);
}
