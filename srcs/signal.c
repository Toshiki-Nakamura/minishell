/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:39:20 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/22 14:31:21 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <libft.h>
#include <unistd.h>
#include "signal_handle.h"
#include "executor.h"

void	sig_func(int sig)
{
	if (sig == SIGINT) /* Ctrl-C */
	{
		set_exit_code(EXIT_FAILURE);
		ft_putstr_fd("\n\033[32mshell$> \033[0m", 1);
	}
	if (sig == SIGQUIT) /* Ctrl-\ */
		write(2, "\b\b", 2);
}

void		sig_process(int sig)
{
	if (sig == SIGINT)	/* Ctrl-C */
	{
		write(2, "\n", 1);
	}
	if (sig == SIGQUIT) /* Ctrl-\ */
	{
		write(2, "Quit: 3\n", 8);
	}
}
