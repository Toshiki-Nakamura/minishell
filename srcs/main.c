/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:42:34 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/19 14:00:51 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_list.h"
#include "prompt.h"
#include "env_list_base.h"
#include <signal_handle.h>
#include "signal.h"
#include "executor.h"

int		main(int ac, char **av, char **env)
{
	int		status;

	(void)av;
	if (ac != 1)
		return (0);
	initialize_env_list(env);
	status = 0;
	while (status >= 0)
	{
		signal(SIGINT, sig_func);
		signal(SIGQUIT, sig_func);
		input_prompt(&status);
		set_exit_status(status);
	}
	finalize_env_list();
	return (0);
}
