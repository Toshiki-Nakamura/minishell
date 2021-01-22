/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_env_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:34:58 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 14:35:20 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSUTILS_ENV_LIST_H
# define MSUTILS_ENV_LIST_H

t_list	*list_dup(t_list *lst);
void	sort_env_list(t_list **env, int (*cmp)(const char *, const char *));

#endif
