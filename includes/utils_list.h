/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:09:51 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/07 10:13:09 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_LIST_H
# define UTILS_LIST_H

# include "libft.h"

void	ft_lst_remove_next(t_list *lst, void (*del)(void *));

#endif
