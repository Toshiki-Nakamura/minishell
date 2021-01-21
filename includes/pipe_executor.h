/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:40:44 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/21 22:28:53 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_EXECUTOR_H
# define PIPE_EXECUTOR_H

int		fork_exec_commands(char **pipe_list);
int		exec_pipe_command(char **pipe_list);

#endif