/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string_operation.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 00:26:09 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/26 14:54:08 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STRING_OPERATION_H
# define UTILS_STRING_OPERATION_H

char	*extract_word(const char *head, int cut_pos, int cut_len, char **word);
char	*replace_word(const char *head, int cut_pos, int cut_len,
		const char *word);

#endif
