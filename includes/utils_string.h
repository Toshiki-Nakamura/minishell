/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:38:56 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/24 12:29:55 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STRING_H
# define UTILS_STRING_H

int		ft_strcmp(const char *str1, const char *str2);
int		ft_cmp_ignore_case(const char *s1, const char *s2, size_t n);
char	*ft_join(char *s, char c);
char	*ft_strjoin_free(char *s1, char *s2);
char	**util_split(const char *str, char c);

#endif
