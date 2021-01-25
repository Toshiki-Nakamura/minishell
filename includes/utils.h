/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:43:02 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/24 21:56:45 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minishell.h"

void	array_free(char **array);
int		array_size(char **array);
int		error_handle(char *cmd, char *arg, char *msg, int exitcode);
void	error_force_exit(char *msg);

#endif
