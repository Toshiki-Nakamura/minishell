/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_convert.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:41:07 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/26 14:49:08 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSUTILS_CONVERT_H
# define MSUTILS_CONVERT_H

/*
**	remove after # as comment message
*/
void	remove_comment(char **str);

/*
**	replace ~ to home path
*/
void	replace_tilde(char **str);

/*
**	iterator for replace_tilde etc.
*/
void	iter_array(char **cmd, void (*str_operate)(char **line));

#endif
