/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string_operation.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:26:09 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 10:47:39 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STRING_OPERATION_H
# define UTILS_STRING_OPERATION_H

/*
**	cが印刷可能文字(ファイル名に使えるか)を判定する。その際、exceptは例外とする
*/
int		is_printable(char c, char *except);

/*
**	headから開始する文字列のうち、cut_posの位置からcut_lenの長さを切り出し、wordに格納する
*/
char	*extract_word(const char *head, int cut_pos, int cut_len, char **word);

/*
**	headから開始する文字列のうち、cut_posの位置からcut_lenの長さを、wordに置き換える。
*/
char	*replace_word(const char *head, int cut_pos, int cut_len,
		const char *word);

#endif
