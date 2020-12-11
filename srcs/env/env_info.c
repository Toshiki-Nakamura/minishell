/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:32:13 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/11 17:14:49 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "env_info.h"
#include "utils_list.h"
#include "utils_string.h"

t_list	*g_env_list_top;
char	*g_env_question;
char	**g_env;

// env_show.c に移動予定
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
// env_show.c に移動予定


static t_env_info		*set_key_only(const char *key)
{
	t_env_info	*info;

	if (!(info = malloc(sizeof(t_env_info))))
		return (NULL);
	info->key = ft_strdup(key);
	info->value = NULL;
	return (info);
}

t_env_info	*create_env_info(const char *env)
{
	t_env_info	*info;
	char		*p;
	int			key_size;

	if (!(info = malloc(sizeof(t_env_info))))
		return (NULL);
	if (!(p = ft_strchr(env, '=')))
	{
		free(info);
		return (set_key_only(env));
	}
	key_size = p - env;
	if (!(info->key = malloc(key_size + 1)))
	{
		free(info);
		return (NULL);
	}
	ft_strlcpy(info->key, env, key_size + 1);
	p++;
	info->value = ft_strdup(p);
	return (info);
}

void		delete_env_info(void *info)
{
	t_env_info	*p;

	if (!info)
		return ;
	p = (t_env_info*)info;
	if (p->key != NULL)
		free(p->key);
	if (p->value != NULL)
		free(p->value);
	free(p);
}

int			cmp_env_key(void *info, const char *key)
{
	t_env_info	*p;

	p = (t_env_info*)info;
	if (!ft_strcmp(p->key, key))
	{
		return (0);
	}
	return (1);
}
