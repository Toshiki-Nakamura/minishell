/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:03:15 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 12:12:06 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include <stdlib.h>
#include "libft.h"
#include "env_info.h"
#include "utils_string.h"
#include "utils_list.h"


static t_env_info	*find_env_info(const char *key)
{
	t_list		*p;

	p = g_env_list_top;
	while (p)
	{
		if (!cmp_env_key(p->content, key))
		{
			return (p->content);
		}
		p = p->next;
	}
	return (NULL);
}

const char			*get_env_value(const char *key)
{
	t_env_info	*p;

	if (!(ft_strcmp(key, ENV_KEY_QUESTION)))
		return (g_env_question);
	if (!(p = find_env_info(key)))
		return (NULL);
	return (p->value);
}

void				set_env_value(const char *env)
{
	t_env_info	*input;
	t_env_info	*p;

	input = create_env_info(env);
	if (!(ft_strcmp(input->key, ENV_KEY_QUESTION)))
	{
		free(g_env_question);
		g_env_question = ft_strdup(input->value);
		delete_env_info(input);
	}
	else if ((p = find_env_info(input->key)))
	{
		if (p->value != NULL)
			free(p->value);
		p->value = ft_strdup(input->value);
		delete_env_info(input);
	}
	else
	{
		ft_lstadd_back(&g_env_list_top, ft_lstnew(input));
	}
}

int					remove_env_value(const char *key)
{
	t_list		*cur;
	t_list		*pre;

	cur = g_env_list_top;
	while (cur)
	{
		if (!cmp_env_key(cur->content, key))
		{
			break ;
		}
		pre = cur;
		cur = cur->next;
	}
	if (!cur)
		return (0);
	ft_lst_remove_next(pre, delete_env_info);
	return (1);
}
