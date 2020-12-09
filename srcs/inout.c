/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:03:44 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/09 12:56:35 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static	int fd_array[256];

char	*dup_redirect_input(const char *filename, size_t *len)
{
	(void)len;
	(void)filename;
	return (NULL);
}

int		set_redirect_output(char *filename, int is_overwrite)
{
	(void)filename;
	fd_array[0] = 0;
	return (is_overwrite);
}

int		output(char *str)
{
	(void)str;
	return (0);
}

void	close_fd(void)
{

}
