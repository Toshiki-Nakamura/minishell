/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:09:51 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/07 15:12:41 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_LIST_H
# define UTILS_LIST_H

# include "libft.h"

/*
** remove next list.
** lst->nextの項目を削除し、その先につながるリストを繋ぎ直す
** *lst 消したいリスト項目を持つリストポインタ
** *del リストのcontentを削除するための関数ポインタ
*/
void	ft_lst_remove_next(t_list *lst, void (*del)(void *));

#endif
