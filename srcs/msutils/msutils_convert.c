/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msutils_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:40:59 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/22 15:13:52 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "utils_string.h"
#include "env_list.h"

void	remove_comment(char **str)
{
	char	*p;
	char	*ret_str;
	size_t	len;

	p = *str;
	while (*p)
	{
		if (*p == '#')
		{
			len = p - *str;
			if (!(ret_str = malloc(len + 1)))
			{
				ft_putstr_fd("", 2);
			}
			ft_strlcpy(ret_str, *str, len + 1);
			free(*str);
			*str = ret_str;
		}
		p++;
	}
}

void	replace_tilde(char **str)
{
    char	    *p;
	char		*ret_str;

    p = *str;
    if (*p != '~')
        return ;
    p++;
	if (!*p || *p == '/')
	{
		ret_str = ft_strjoin(get_env_value("HOME"), p);
		free(*str);
		*str = ret_str;
	}
}

void	iter_array(char **cmd, void (*str_operate)(char **line))
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		str_operate(&cmd[i]);
		i++;
	}
}