/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:29:34 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/17 15:42:11 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIILS_QUOTE_H
# define UTIILS_QUOTE_H

int			is_quote(int c);
char		*parse_line(char *line, int *quote, int *idx);
char		*remove_quote(char *line);
char		*skip_to_next_quote(char *str);

#endif
