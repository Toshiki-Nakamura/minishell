/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:03:44 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/04 22:28:24 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*dup_redirect_input(char *filename)
{
	return (filename);
}

int		get_output_fd(char *filename, int oflag)
{
	(void)filename;
	return (oflag);
}

void	close_fd(int fd)
{
	close(fd);
}
