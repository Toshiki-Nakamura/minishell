/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:42:34 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/10 22:22:50 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_list.h"
#include "prompt.h"
#include "env_list_base.h"

int		main(int ac, char **av, char **env)
{
	int		status;

	(void)av;
	if (ac != 1)
		return (0);
	initialize_env_list(env);
	if (!get_env_value("OLDPWD"))
		set_env_value("OLDPWD");
	status = 1;
	while (status > 0)
	{
		input_prompt(&status);
	}
	finalize_env_list();
	return (0);
}
