/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_param.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:33:52 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 12:05:07 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_ENV_PARAM_H
# define UTILS_ENV_PARAM_H

int		get_envparam_length(const char *cmd);

/*
**	cmdに含まれる文字列から最初の$から始まる環境変数を置き換える
*/
int		replace_env_param(char **cmd);

#endif
