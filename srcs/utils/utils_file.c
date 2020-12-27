/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 14:08:06 by skohraku          #+#    #+#             */
/*   Updated: 2020/12/27 14:52:08 by skohraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int		is_capable_to_create(const char* path)
{
    int fd;

    if (-1 == (fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0666)))
        return 0;
    close(fd);
    return (1);
}