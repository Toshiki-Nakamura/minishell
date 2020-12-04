/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:21 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/04 22:26:56 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INOUT_H
# define INOUT_H

char	*dup_redirect_input(char *filename);
int		get_output_fd(char *filename, int oflag);
void	close_fd(int fd);

#endif
