/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:28:43 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 14:25:36 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "minishell.h"
#include "utils.h"

void	init_redirect_fd(t_fd *fd)
{
	fd->input = STDIN;
	fd->output = STDOUT;
}

int		set_redirect(char *filename, t_fd *fd, t_redirect_type type)
{
	int	*p_fd;
	int	file_fd;
	int	std_fd;
	int flags;

	if (type == REDIRECT_INPUT)
		flags = O_RDONLY;
	else if (type == REDIRECT_OVERRIDE)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	else
		flags = O_WRONLY | O_CREAT | O_APPEND;
	if ((file_fd = open(filename, flags, 0666)) < 0)
	{
		error_handle(filename, NULL, strerror(errno), 1);
		return (1);
	}
	p_fd = (type == REDIRECT_INPUT) ? &(fd->input) : &(fd->output);
	std_fd = dup(*p_fd);
	close(*p_fd);
	dup2(file_fd, ((type == REDIRECT_INPUT) ? STDIN : STDOUT));
	close(file_fd);
	*p_fd = std_fd;
	return (0);
}

void	undo_redirect_fd(t_fd fd)
{
	if (fd.input != STDIN)
	{
		dup2(fd.input, STDIN);
		close(fd.input);
	}
	if (2 < fd.output)
	{
		dup2(fd.output, STDOUT);
		close(fd.output);
	}
}
