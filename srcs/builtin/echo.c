/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:42:42 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/25 13:20:18 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "utils_string.h"


int			exec_echo(char **args)
{
	int	i;

	i = 1;
	if (args[1] == NULL)
		ft_putstr_fd("", 1);
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
		i++;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		i++;
		if (args[i] != NULL)
			write(1, " ", 1);
	}
	if (!args[1] || ft_strcmp(args[1], "-n") != 0)
		write(1, "\n", 1);
	return (0);
}
