/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_signal.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:41:12 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/22 15:22:22 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_SIGNAL_H
# define MY_SIGNAL_H

# include "libft.h"
# include <signal.h>

void		in_prompt(int sig);
void		in_process(int sig);
void		sig_ignore(int sig);

#endif
