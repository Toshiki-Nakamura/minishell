/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 13:44:31 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/10 12:51:40 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils_string.h"
#include "cmd_manager.h"

static char	*get_cmd_line(void)
{
	char	*line;
	char	buf;
	int		ret;

	line = ft_strdup("");
	while ((ret = read(0, &buf, 1)))
	{
		if (buf == '\n')
			break ;
		line = ft_join(line, buf);
	}
	if (ret == -1)
		exit(0);
	return (line);
}

void		input_prompt(int *status)
{
	int		fd;
	char	*line;

	fd = 1;
	ft_putstr_fd("\033[32mshell$> \033[0m", 1);
	line = get_cmd_line(); // !!! wait return !!!

	*status = exec_command_line(line);
	if (line != NULL)
		free(line);
}
