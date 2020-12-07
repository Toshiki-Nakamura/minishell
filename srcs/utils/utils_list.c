/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:10:44 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/07 10:17:58 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_remove_next(t_list *lst, void (*del)(void *))
{
	t_list *tmp;

	if (!lst || !del || !lst->next)
		return ;
	tmp = lst->next->next;
	ft_lstdelone(lst->next, del);
	lst->next = tmp;
}