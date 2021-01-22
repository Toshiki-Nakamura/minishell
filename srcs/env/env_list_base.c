/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:01:41 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 14:39:33 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils_string.h"
#include "utils_list.h"
#include "env_info.h"
#include "env_list.h"

void				initialize_env_list(char **env)
{
	char	*p;
	t_list	*plist;

	if (g_env_list_top)
		return ;
	g_env_list_top = NULL;
	g_env_question = ft_strdup("0");
	g_env = env;
	while ((p = *env))
	{
		plist = ft_lstnew(create_env_info(p));
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
	return (g_env);
}
