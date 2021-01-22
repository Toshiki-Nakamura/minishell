/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 18:36:38 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 15:06:28 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_list.h"
#include "utils_string.h"
#include "env_info.h"
#include "env_list.h"

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

static void		sort_env_list(t_list **env, int (*cmp)(const char *, const char *))
{
	t_list *tmp_i;
	t_list *tmp_j;

	tmp_i = *env;
	while (tmp_i)
	{
		tmp_j = tmp_i->next;
		while (tmp_j)
		{
			if (cmp(((t_env_info *)tmp_i->content)->key, \
								((t_env_info *)tmp_j->content)->key) > 0)
			{
				ft_swap(&tmp_i->content, &tmp_j->content);
			}
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}

void			show_export_list(void)
{
	t_list *p;

	p = ft_list_dup(g_env_list_top, copy_env_info);
	sort_env_list(&p, &ft_strcmp);
	ft_lstiter(p, show_info_for_export);
	ft_lstclear(&p, &delete_env_info);
}
