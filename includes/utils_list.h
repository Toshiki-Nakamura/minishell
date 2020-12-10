/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:09:51 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/10 17:54:04 by tnakamur         ###   ########.fr       */
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
** list_dup.
** *env_lstの複製
** lst->content(t_env_info)をmallocしてlstadd している
** sort_env_list.
** envのリストをkeyの辞書順でsort
*/
void	ft_lst_remove_next(t_list *lst, void (*del)(void *));
t_list	*list_dup(t_list *lst);
void	sort_env_list(t_list **env, int (*cmp)(const char *, const char *));

#endif
