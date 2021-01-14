/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:55:07 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/14 19:18:57 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_SYNTAX_H
# define UTILS_SYNTAX_H

# define EOF_ERROR  "unexpected end of file"

int		put_syntax_err(char *msg, char token, int exitcode);
int		parse_syntax(const char *str);
int		check_closed(const char *str, char token);

#endif
