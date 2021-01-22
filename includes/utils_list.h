/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:09:51 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 14:34:52 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_LIST_H
# define UTILS_LIST_H

# include "libft.h"

void	ft_swap(void **l1, void **l2);
/*
** remove next list.
** lst->nextの項目を削除し、その先につながるリストを繋ぎ直す
** *lst 消したいリスト項目を持つリストポインタ
** *del リストのcontentを削除するための関数ポインタ
** list_dup.
** *env_lstの複製
** lst->content(t_env_info)をmallocしてlstadd している
** sort_env_list.
** envのリストをkeyの辞書順でsort
*/
void	ft_lst_remove_next(t_list *lst, void (*del)(void *));

#endif
