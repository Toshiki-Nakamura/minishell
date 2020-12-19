/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:45:46 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/19 14:01:10 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

int		g_old_status;

int		exec_command(char *cmd);
int		sh_execute(char **args, char **env, int fd);
int		is_builtin(char *cmd);
void	set_exit_status(int status);

#endif
