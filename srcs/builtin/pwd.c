/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:35:38 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/21 21:17:00 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "libft.h"
#include "env_list.h"

int			exec_pwd(void)
{
	char	path[MAXPATHLEN];

	ft_memset(path, 0, MAXPATHLEN);
	if (!getcwd(path, MAXPATHLEN))
		return (1);
	ft_putendl_fd(path, 1);
	return (0);
}
