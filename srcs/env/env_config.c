/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:01:41 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/25 13:41:26 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils.h"
#include "utils_string.h"
#include "utils_list.h"
#include "env_info.h"
#include "env_list.h"

static char		**g_env_param;

void				initialize_env_list(char **env)
{
	char		*p;
	t_list		*plist;
	t_env_info	*pinfo;

	if (g_env_list_top)
		return ;
	g_env_list_top = NULL;
	g_env_question = ft_strdup("0");
	g_env_param = env;
	while ((p = *env))
	{
		if (!(pinfo = create_env_info(p)))
			error_force_exit(MALLOC_ERROR);
		plist = ft_lstnew(pinfo);
		ft_lstadd_back(&g_env_list_top, plist);
		env++;
	}
	if (!get_env_value("OLDPWD"))
		set_env_value("OLDPWD");
}

void				finalize_env_list(void)
{
	ft_lstclear(&g_env_list_top, delete_env_info);
	free(g_env_question);
}

char				**get_env_param(void)
{
	return (g_env_param);
}
