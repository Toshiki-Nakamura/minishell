/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:54:33 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/24 15:26:46 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

int		exec_pwd(int fd);
int		exec_cd(char **args, char **env);
void	exec_exit(char **args);
int		exec_env(char **args, char **env, int fd);
int		exec_echo(char **args, int fd);
int		exec_unset(char **args);
int		exec_export(char **args, int fd);
int		exec_execve(char **args, char **env, int fd);

#endif
