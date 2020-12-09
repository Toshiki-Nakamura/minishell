/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:21 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/09 12:56:39 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INOUT_H
# define INOUT_H

char	*dup_redirect_input(char *filename);
int		set_redirect_output(char *filename, int oflag);
int		output(char *str);
void	close_fd();

#endif
