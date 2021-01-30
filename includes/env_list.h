/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:01:48 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/11 17:16:04 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_H
# define ENV_LIST_H

# include "libft.h"

const char	*get_env_value(const char *key);
void		set_env_value(const char *env);
int			remove_env_value(const char *key);

#endif
