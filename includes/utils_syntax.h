/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_syntax.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 23:55:07 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/31 14:20:37 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_SYNTAX_H
# define UTILS_SYNTAX_H

int		syntax_check(const char *str, char token);
int		last_word(char *str, char token);
char	*check_token(char *line, char token);

#endif
