/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inout.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:02:21 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/14 14:56:21 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

int		set_redirect_input(char *filename);
int		set_redirect_output(char *filename, int is_overwrite);
int		undo_redirect_fd(int input, int output);

#endif
