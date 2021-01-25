/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string_operation.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:26:09 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/24 22:02:11 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STRING_OPERATION_H
# define UTILS_STRING_OPERATION_H

/*
**	headから開始する文字列のうち、cut_posの位置からcut_lenの長さを切り出し、wordに格納する
**	戻り値：抽出後の文字列。mallocエラーの場合はnullを返す
*/
char	*extract_word(const char *head, int cut_pos, int cut_len, char **word);

/*
**	headから開始する文字列のうち、cut_posの位置からcut_lenの長さを、wordに置き換える。
**	戻り値：置き換え後の文字列。mallocエラーの場合はnullを返す
*/
char	*replace_word(const char *head, int cut_pos, int cut_len,
		const char *word);

#endif
