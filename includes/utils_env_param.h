/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env_param.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:33:52 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/27 00:59:35 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_ENV_PARAM_H
# define UTILS_ENV_PARAM_H

/*
**	環境変数のKeyとして使用可能か判定する
**	$HOGE, HOGE,  HOGE=XXX などの入力に対応。
**	先頭の$は読み飛ばす。=があれば判定を終了する
*/
int		is_invalid_env_name(const char *key);

int		get_envparam_length(const char *cmd);

/*
**	cmdに含まれる文字列から最初の$から始まる環境変数を置き換える
**	内部で再起的に呼び出されるため、最初に呼び出した側の戻り値は0になる。
**	return : 置き換えが発生したら1, 無ければ0
*/
int		replace_env_param(char **cmd);

/*
**	g_envに格納した最初の環境変数から
**	keyに紐づくvalueを返す。なければNULL
*/
const char	*g_env_value(char *key);

#endif
