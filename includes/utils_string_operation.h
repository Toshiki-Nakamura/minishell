/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string_operation.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:26:09 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/04 16:46:52 by tnakamur         ###   ########.fr       */
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

/*
**	#以降をコメントとして削除する
*/
void	remove_comment(char **str);

/*
**	各コマンドリストにreplace_tildeなどの関数を適用
*/
void	iter_array(char **cmd, void (*str_operate)(char **line));

#endif
