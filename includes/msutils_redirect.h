/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_redirect.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:20:51 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/25 19:34:41 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSUTILS_REDIRECT_H
# define MSUTILS_REDIRECT_H

# include "minishell.h"

void	init_redirect_fd(t_fd *fd);
int		set_redirect(char *filename, t_fd *fd, t_redirect_type type);
void	undo_redirect_fd(t_fd fd);

#endif
