/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:54:33 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/21 21:25:48 by tnakamur         ###   ########.fr       */
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
int		exec_execve(char **args, char **env);

#endif
