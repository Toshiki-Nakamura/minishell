/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_executor.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 22:40:44 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/09 16:06:28 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_EXECUTOR_H
# define PIPE_EXECUTOR_H

int		fork_exec_commands(int cmd_num, char **pipe_list);

#endif