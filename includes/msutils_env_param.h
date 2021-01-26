/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_env_param.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:33:52 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/26 14:49:26 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSUTILS_ENV_PARAM_H
# define MSUTILS_ENV_PARAM_H

int		is_invalid_env_name(const char *key);
int		get_envparam_length(const char *cmd);
int		replace_env_param(char **cmd);
void	set_exit_code(int code);

#endif
