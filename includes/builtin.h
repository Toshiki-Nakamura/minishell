/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:54:33 by skohraku          #+#    #+#             */
/*   Updated: 2020/11/30 13:54:50 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		exec_pwd(int fd);
int		exec_cd(char **args, char **env);
void	exec_exit(char **args);
int		exec_env(char **args, char **env, int fd);

#endif