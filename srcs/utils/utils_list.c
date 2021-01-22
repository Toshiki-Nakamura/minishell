/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:10:44 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 14:52:16 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"

void	ft_swap(void **l1, void **l2)
{
	void *tmp;

	tmp = *l1;
	*l1 = *l2;
	*l2 = tmp;
}

void	ft_lst_remove_next(t_list *lst, void (*del)(void *))
{
	t_list *tmp;

	if (!lst || !del || !lst->next)
		return ;
	tmp = lst->next->next;
	ft_lstdelone(lst->next, del);
	lst->next = tmp;
}

t_list	*ft_list_dup(t_list *lst, void *(copy(t_list *)))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	tmp = lst;
	while (tmp)
	{
		ft_lstadd_back(&new, ft_lstnew(copy(tmp)));
		tmp = tmp->next;
	}
	return (new);
}
