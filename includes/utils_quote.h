/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:29:34 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/14 14:45:02 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIILS_QUOTE_H
# define UTIILS_QUOTE_H

int		is_quote(int c);
char	*skip_to_next_quote(const char *str);
void	remove_quote(char **line);

#endif
