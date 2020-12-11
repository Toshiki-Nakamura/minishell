/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:32:13 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/11 19:01:11 by tnakamur         ###   ########.fr       */
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
