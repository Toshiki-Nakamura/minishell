/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_convert.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:41:07 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 13:50:39 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSUTILS_CONVERT_H
# define MSUTILS_CONVERT_H

/*
**	#以降をコメントとして削除する
*/
void	remove_comment(char **str);

/*
**	~をホームパスに置き換える
*/
void	replace_tilde(char **str);

/*
**	各コマンドリストにreplace_tildeなどの関数を適用
*/
void	iter_array(char **cmd, void (*str_operate)(char **line));

#endif
