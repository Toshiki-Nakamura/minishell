/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:14:10 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/11 18:52:44 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <errno.h>
#include <sys/param.h>
#include "env_list.h"
#include "env_show.h"

int			exec_env(char **args, char **env, int fd)
{
	(void)args;
	(void)env;
	(void)fd;
	set_env_value("_=/usr/bin/env");
	show_env_list();
	return (1);
}
