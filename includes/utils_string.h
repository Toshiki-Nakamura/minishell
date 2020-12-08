/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 21:38:56 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/08 18:12:45 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_STRING_H
# define UTILS_STRING_H

int		ft_strcmp(const char *str1, const char *str2);
int		ft_strncmp_ex(const char *s1, const char *s2, size_t n);
char	*ft_join(char *s, char c);
char	*ft_strjoin_free(char *s1, char *s2);

#endif
