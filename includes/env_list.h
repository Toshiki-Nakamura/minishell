/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:01:48 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/04 22:51:21 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_H
# define ENV_LIST_H

# include "libft.h"

void		initialize_env_list(char **env);
void		finalize_env_list();
void		show_env_list(void);
const char	*get_env_value(const char *key);
void		set_env_value(const char *env);
void		remove_env_value(const char *key);

#endif