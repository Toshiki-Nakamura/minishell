/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_syntax.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:55:07 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 14:23:24 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSUTILS_SYNTAX_H
# define MSUTILS_SYNTAX_H

# define EOF_ERROR  "unexpected end of file"

int		put_syntax_err(char *msg, char token, int exitcode);
int		parse_syntax(const char *str);
int		check_closed(const char *str, char token);

#endif
