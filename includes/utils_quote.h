/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quote.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:29:34 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/25 19:40:00 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_QUOTE_H
# define UTILS_QUOTE_H

char	*skip_to_next_quote(const char *str);
void	remove_quote(char **line);

#endif
