/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:35:38 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/19 12:32:20 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"

int			exec_pwd(int fd)
{
	char	path[MAXPATHLEN];

	ft_memset(path, 0, MAXPATHLEN);
	if (!getcwd(path, MAXPATHLEN))
		return (1);
	ft_putendl_fd(path, fd);
	return (0);
}
