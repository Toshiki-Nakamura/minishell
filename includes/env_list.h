/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:01:48 by skohraku          #+#    #+#             */
/*   Updated: 2020/11/30 14:24:41 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_H
# define ENV_LIST_H

# include "libft.h"

t_list	**init_env_list(char **env);
void	finalize_env_list();
int		is_valid_env_list(const char *key);
int		set_env_value(const char *key, const char *value);
char	*get_env_value(const char *key);

#endif