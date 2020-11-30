/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:43:02 by skohraku          #+#    #+#             */
/*   Updated: 2020/11/30 13:43:26 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_strncmp_ex(const char *s1, const char *s2, size_t n);
void	tab_free(char **tab);
int		tab_size(char **tab);
char	*ft_join(char *s, char c);

#endif