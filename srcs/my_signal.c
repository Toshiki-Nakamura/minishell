/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 22:39:20 by tnakamur          #+#    #+#             */
/*   Updated: 2021/10/31 13:19:01 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"
#include "minishell.h"
#include "utils_string.h"
#include "msutils_env_param.h"
#include "prompt.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void		in_prompt(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1); 
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
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
