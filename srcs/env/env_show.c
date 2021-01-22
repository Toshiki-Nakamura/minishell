/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:36:38 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 14:39:54 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_list.h"
#include "utils_string.h"
#include "env_info.h"
#include "env_list.h"
#include "msutils_env_list.h"

static void		show_info_for_env(void *info)
{
	t_env_info	*p;

	p = (t_env_info *)info;
	if (!p->value)
		return ;
	ft_putstr_fd(p->key, 1);
	ft_putstr_fd("=", 1);
	ft_putstr_fd(p->value, 1);
	ft_putstr_fd("\n", 1);
}

static void		show_info_for_export(void *info)
{
	t_env_info	*p;

	p = (t_env_info *)info;
	if ((p->key[0] == '_' && p->key[1] == '\0'))
		return ;
	ft_putstr_fd("declare -x ", 1);
	ft_putstr_fd(p->key, 1);
	if (p->value)
	{
		ft_putstr_fd("=\"", 1);
		ft_putstr_fd(p->value, 1);
		ft_putstr_fd("\"", 1);
	}
	ft_putchar_fd('\n', 1);
}

void			show_env_list(void)
{
	ft_lstiter(g_env_list_top, show_info_for_env);
}

void			show_export_list(void)
{
	t_list *p;

	p = list_dup(g_env_list_top);
	sort_env_list(&p, &ft_strcmp);
	ft_lstiter(p, show_info_for_export);
	ft_lstclear(&p, &delete_env_info);
}
