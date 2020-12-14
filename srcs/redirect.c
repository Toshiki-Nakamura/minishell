/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:03:44 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/14 14:13:19 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

#define STDIN	0
#define STDOUT	1

int		set_redirect_input(char *filename)
{
	int	fd_in;
	int	fd_std_input;

	if ((fd_in = open(filename, O_RDONLY)) < 0) {
		perror("redirect input open");
		close(fd_in);
		return (-1);
	}
	fd_std_input = dup(STDIN);
	close(0);
	dup2(fd_in, 0);
	close(fd_in);
	return (fd_std_input);
}

int		set_redirect_output(char *filename, int is_overwrite)
{
	int	fd_out;
	int flags;
	int	fd_std_output;

	flags = is_overwrite ? O_WRONLY|O_CREAT|O_TRUNC :
					O_WRONLY|O_CREAT|O_APPEND;
	if ((fd_out = open(filename, flags, 0666)) < 0) {
		perror("redirect open");
		close(fd_out);
		return (-1);
	}
	fd_std_output = dup(STDOUT);
	close(1);
	dup2(fd_out, 1);
	close(fd_out);
	return (fd_std_output);
}

int		undo_redirect_fd(int input, int output)
{
	if (input != STDIN)
	{
		dup2(input, STDIN);
		close(input);
	}
	if (2 < output)
	{
		dup2(output, STDOUT);
		close(output);
	}
	return (0);
}
