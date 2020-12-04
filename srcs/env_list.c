/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:03:15 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/04 22:54:23 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "env_info.h"
#include "utils_string.h"

#define ENV_KEY_QUESTION	"?"

static char		*g_env_question;
static t_list	*g_env_list_top;



void				initialize_env_list(char **env)
{
	char	*p;
	t_list	*plist;

	g_env_question = NULL;
	g_env_list_top = NULL;
	while ((p = *env))
	{
		plist = ft_lstnew(create_env_info(p));
		ft_lstadd_back(&g_env_list_top, plist);
		env++;
	}
}

void				finalize_env_list(void)
{
	ft_lstclear(&g_env_list_top, delete_env_info);
}

void				show_env_list(void)
{
	show_env_list_contents(g_env_list_top, 0);
}

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
		free(p->value);
		p->value = ft_strdup(input->value);
		delete_env_info(input);
	}
	else
	{
		ft_lstadd_back(&g_env_list_top, ft_lstnew(input));
	}
}

void				remove_env_value(const char *key)
{
	(void)key;
}
