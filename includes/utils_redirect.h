/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirect.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:20:51 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 12:24:23 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_REDIRECT_H
# define UTILS_REDIRECT_H

int			get_redirect_length(const char *cmd);

/*
**	cmdに含まれる文字列から最初のリダイレクトとファイル名を抽出し、cmdと分離する
**	return : 分離が発生したら1, 無ければ0
*/
int			separate_redirect_word(char **cmd, char **word);

#endif