/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_config.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:04:34 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/25 13:35:13 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENV_CONFIG_H
# define ENV_CONFIG_H

void	initialize_env_list(char **env);
void	finalize_env_list(void);
char	**get_env_param(void);

#endif
