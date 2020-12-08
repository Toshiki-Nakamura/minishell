/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_base.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:04:34 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/07 22:05:11 by skohraku         ###   ########.fr       */
/*   Updated: 2020/12/08 15:45:29 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_BASE_H
# define ENV_LIST_BASE_H

void	initialize_env_list(char **env);
void	finalize_env_list(void);
char	**get_env_param(void);

#endif
