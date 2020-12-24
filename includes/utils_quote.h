/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:29:34 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/24 12:30:12 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIILS_QUOTE_H
# define UTIILS_QUOTE_H

int			is_quote(int c);
void		parse_line(char *line, int *quote);
char		*skip_to_next_quote(char *str);
void		iter_remove_quote(char **cmd);

#endif
