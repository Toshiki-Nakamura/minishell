/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:42:34 by skohraku          #+#    #+#             */
/*   Updated: 2021/08/23 17:16:26 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "env_config.h"
#include "my_signal.h"
#include "prompt.h"

void	init_msg(void)
{
	ft_putstr_fd("\033[36m", 2);
	ft_putendl_fd("███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗     ", 2);
	ft_putendl_fd("████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║     ", 2);
	ft_putendl_fd("██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║     ", 2);
	ft_putendl_fd("██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║     ", 2);
	ft_putendl_fd("██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║███████╗███████╗███████╗", 2);
	ft_putendl_fd("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════", 2);
	ft_putendl_fd("\033[0,", 2);
}

int		main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
		return (0);
	init_msg();
	initialize_env_list(env);
	while (1)
	{
		signal(SIGINT, in_prompt);
		signal(SIGQUIT, in_prompt);
		input_prompt();
	}
	return (0);
}
