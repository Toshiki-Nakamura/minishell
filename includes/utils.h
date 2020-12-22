/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:43:02 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/20 14:54:55 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	array_free(char **array);
int		array_size(char **array);
void	ft_swap(void **l1, void **l2);
int		error_handle(char *cmd, char *arg, char *msg, int exitcode);

#endif
