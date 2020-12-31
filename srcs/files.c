/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:17:34 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/30 16:04:22 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils_string.h"
#include "env_list.h"

void       replace_tilde(char **str)
{
    char	    *p;
	const char	*user;
	char		*ret_str;

    p = *str;
    if (*p != '~')
        return ;
    p++;
	user = get_env_value("USER");
    if (0 == ft_strncmp(p, user, ft_strlen(user)))
		p += ft_strlen(user);
	if (!*p || *p == '/')
	{
		ret_str = ft_strjoin(get_env_value("HOME"), p);
		free(*str);
		*str = ret_str;
	}
}
