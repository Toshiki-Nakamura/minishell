/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:32:13 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/04 22:52:33 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "env_info.h"
#include "utils_string.h"

void		show_env_list_contents(t_list *p, int is_reverse)
{
	if (!p)
		return ;
	if (is_reverse)
		show_env_list_contents(p->next, is_reverse);
	show_env_info(p->content);
	if (!is_reverse)
		show_env_list_contents(p->next, is_reverse);
}

t_env_info	*create_env_info(const char *env)
{
	t_env_info	*info;
	char		*p;
	int			key_size;

	if (!(info = malloc(sizeof(t_env_info))))
		return (NULL);
	p = ft_strchr(env, '=');
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
	free(p->key);
	free(p->value);
	free(p);
}

void		show_env_info(void *info)
{
	t_env_info	*p;

	p = (t_env_info *)info;
	ft_putstr_fd(p->key, 1);
	ft_putstr_fd("=", 1);
	ft_putstr_fd(p->value, 1);
	ft_putstr_fd("\n", 1);
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
