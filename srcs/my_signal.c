/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:39:20 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/14 14:51:18 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <libft.h>
#include <unistd.h>
#include "executor.h"
#include "prompt.h"
#include "utils_string.h"

void		in_prompt(int sig)
{
	if (sig == SIGINT) /* Ctrl-C */
	{
		write(2, "\b \b\b \b", 6);
		if (ft_strcmp(g_line, "") != 0) /* ctrl-D が先に打たれていたら */
		{
			free_set(&g_line, ft_strdup(""));
		}
		set_exit_code(EXIT_FAILURE);
		ft_putstr_fd("\n\033[32mshell$> \033[0m", 2);
	}
	if (sig == SIGQUIT) /* Ctrl-\ */
		write(2, "\b \b\b \b", 6);
}

void		in_process(int sig)
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

void		sig_ignore(int sig)
{
	(void)sig;
	return ;
}