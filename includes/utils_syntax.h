/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:55:07 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/06 01:17:16 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_SYNTAX_H
# define UTILS_SYNTAX_H

# define EOF_ERROR  "unexpected end of file"

int		syntax_check(const char *str);
int		last_word(char *str, char token);
char	*check_token(char *line, char token);
int		syntax_error(char *msg, char token, int exitcode);

#endif
