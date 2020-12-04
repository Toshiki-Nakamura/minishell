/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_info.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 20:39:08 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/04 22:27:24 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_INFO_H
# define ENV_INFO_H

typedef struct	s_env_info
{
	char	*key;
	char	*value;
}				t_env_info;

t_env_info		*create_env_info(const char *env);
void			delete_env_info(void *info);
void			show_env_info(void *info);
int				cmp_env_key(void *info, const char *key);

#endif
