/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:21 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/26 14:52:10 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

const char		*skip_redirect_mark(const char *redirect,
				t_redirect_type *type);

/*
** get redirect syntax length
** 0: not find redirect
** n: return redirect mark and filename length
*/
int				get_redirect_length(const char *redirect);

/*
** separate redirect type and filename
*/
void			separate_redirect_info(char **redirect, t_redirect_type *type);

/*
**	separate redirect and filename from command
**	return : 1-separate is success, 0-redirect is not found.
*/
int				separate_redirect_word(char **cmd, char **word);

#endif
