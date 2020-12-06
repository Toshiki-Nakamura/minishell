/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:48:13 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/06 17:56:38 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"

void		exec_execve(char **args, char **env, int fd)
{
	(void)fd;
	if ((execve(args[0], args, env)) == -1)
	{
		ft_putstr_fd("shell: ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	exit(EXIT_FAILURE);
}
