/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_is.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 14:07:47 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 14:18:41 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_IS_H
# define UTILS_IS_H

int		is_quote(int c);
int		is_space(char c);
/*
**	cが印刷可能文字(ファイル名に使えるか)を判定する。その際、exceptは例外とする
*/
int		is_printable(char c, char *except);
int		is_control_operator(int c);
int		is_redirect_operator(int c);

#endif
