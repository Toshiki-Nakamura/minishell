/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirect.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:20:51 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/16 00:36:25 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_REDIRECT_H
# define UTILS_REDIRECT_H

int			get_redirect_length(const char *cmd);
int			get_envparam_length(const char *cmd);
char		*extract_redirect_word(const char *cmd, char **word);
char		*replace_env_param(const char *cmd);

#endif