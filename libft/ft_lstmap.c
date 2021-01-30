/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:43:47 by tnakamur          #+#    #+#             */
/*   Updated: 2020/06/29 17:42:36 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *map;
	t_list *new;

	if (!lst)
		return (lst);
	map = lst;
	if (!map)
		return (map);
	new = NULL;
	while (lst != NULL)
	{
		map = ft_lstnew(f(lst->content));
		if (map == NULL)
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, map);
		lst = lst->next;
	}
	return (new);
}
