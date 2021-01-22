/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_env_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:32:03 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 14:33:00 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_list.h"
#include "env_info.h"

void				sort_env_list(t_list **env, int (*cmp)(const char *, const char *))
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

static t_env_info	*cpy_env_info(t_list *lst)
{
	t_env_info *new;

	new = malloc(sizeof(t_env_info *));
	new->key = ft_strdup(((t_env_info *)lst->content)->key);
	new->value = ft_strdup(((t_env_info *)lst->content)->value);
	return (new);
}

t_list				*list_dup(t_list *lst)
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = lst;
	while (tmp)
	{
		ft_lstadd_back(&new, ft_lstnew(cpy_env_info(tmp)));
		tmp = tmp->next;
	}
	return (new);
}