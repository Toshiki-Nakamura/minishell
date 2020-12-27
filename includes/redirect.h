/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:21 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/27 10:34:31 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

const char		*skip_redirect_mark(const char *redirect,
				t_redirect_type *type);

/*
** cmdの先頭の位置から、リダイレクト処理部の長さを求める
** 0: リダイレクトに該当しない
** n: リダイレクトに該当する。記号とファイル名の長さを返す
** -1: リダイレクト非対応に該当する
*/
int				get_redirect_length(const char *redirect);

/*
** リダイレクト判定をして切り出した文字列を、記号とファイル名に分割する
*/
void			separate_redirect_info(char **redirect, t_redirect_type *type);

/*
**	cmdに含まれる文字列から最初のリダイレクトとファイル名を抽出し、cmdと分離する
**	return : 分離が発生したら1, 無ければ0
*/
int				separate_redirect_word(char **cmd, char **word);

#endif
