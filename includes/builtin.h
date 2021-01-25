/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:54:33 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/25 13:27:44 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		exec_cd(char **args);
int		exec_pwd(void);
int		exec_env(char **args);
void	exec_exit(char **args);
int		exec_echo(char **args);
int		exec_unset(char **args);
int		exec_export(char **args);
int		exec_execve(char **args);

#endif
