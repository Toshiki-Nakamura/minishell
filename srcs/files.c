/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 15:17:34 by skohraku          #+#    #+#             */
/*   Updated: 2021/01/15 11:25:06 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "utils_string.h"
#include "env_list.h"

void       replace_tilde(char **str)
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
