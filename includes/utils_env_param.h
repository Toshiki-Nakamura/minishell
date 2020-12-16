/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_param.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:33:52 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 12:45:28 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_ENV_PARAM_H
# define UTILS_ENV_PARAM_H

int		get_envparam_length(const char *cmd);

/*
**	cmdに含まれる文字列から最初の$から始まる環境変数を置き換える
**	内部で再起的に呼び出されるため、最初に呼び出した側の戻り値は0になる。
**	return : 置き換えが発生したら1, 無ければ0
*/
int		replace_env_param(char **cmd);

#endif
