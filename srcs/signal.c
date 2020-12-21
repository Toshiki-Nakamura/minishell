/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:39:20 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/21 14:17:37 by skohraku         ###   ########.fr       */
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
		set_exit_code(1);
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
