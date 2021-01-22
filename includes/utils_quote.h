/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:29:34 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 14:07:41 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIILS_QUOTE_H
# define UTIILS_QUOTE_H

char	*skip_to_next_quote(const char *str);
void	remove_quote(char **line);

#endif
