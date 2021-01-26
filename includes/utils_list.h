/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:09:51 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/26 14:52:32 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_LIST_H
# define UTILS_LIST_H

# include "libft.h"

void	ft_swap(void **l1, void **l2);
void	ft_lst_remove_next(t_list *lst, void (*del)(void *));
t_list	*ft_list_dup(t_list *lst, void *(copy(t_list *)));

#endif
