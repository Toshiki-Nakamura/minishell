/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirect.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:20:51 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/18 11:34:42 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_REDIRECT_H
# define UTILS_REDIRECT_H

typedef enum	e_redirection {
	REDIRECT_INPUT,
	REDIRECT_OVERRIDE,
	REDIRECT_APPEND,
	REDIRECT_NONE,
}				t_redirection;

const char		*skip_redirect_mark(const char *cmd, t_redirection *type);

void			separate_redirect_info(char **cmd, t_redirection *type);

int				get_redirect_length(const char *cmd);

/*
**	cmdに含まれる文字列から最初のリダイレクトとファイル名を抽出し、cmdと分離する
**	return : 分離が発生したら1, 無ければ0
*/
int				separate_redirect_word(char **cmd, char **word);

#endif