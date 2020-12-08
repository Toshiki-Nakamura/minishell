/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:40:44 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/08 18:28:24 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_EXECUTOR_H
# define PIPE_EXECUTOR_H

int		exec_command(char *cmd);
int		exec_pipe_list(int cmd_num, char **pipe_list);

#endif