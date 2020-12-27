/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirect.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:20:51 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/27 11:08:34 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_REDIRECT_H
# define UTILS_REDIRECT_H

# include "minishell.h"

void	init_redirect_fd(t_fd *fd);
int		set_redirect(char *filename, t_fd *fd, t_redirect_type type);
void	undo_redirect_fd(t_fd fd);

#endif