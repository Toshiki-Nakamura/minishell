/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:01:48 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/07 22:05:34 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_H
# define ENV_LIST_H

# include "libft.h"

void		show_env_list(void);
const char	*get_env_value(const char *key);
void		set_env_value(const char *env);
int			remove_env_value(const char *key);

#endif
