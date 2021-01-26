/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:39:20 by tnakamur          #+#    #+#             */
/*   Updated: 2021/01/26 12:53:37 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "minishell.h"
#include "utils_string.h"
#include "msutils_env_param.h"
#include "prompt.h"

void		in_prompt(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\b \b\b \b", 6);
		if (ft_strcmp(g_line, "") != 0)
		{
			free_set(&g_line, ft_strdup(""));
		}
		set_exit_code(EXIT_FAILURE);
		write(2, "\n", 1);
		ft_putstr_fd(PROMPT, 2);
	}
	if (sig == SIGQUIT)
		write(2, "\b \b\b \b", 6);
}

void		in_process(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
	}
	if (sig == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
	}
}

void		sig_ignore(int sig)
{
	(void)sig;
	return ;
}
