/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:27:17 by tnakamur          #+#    #+#             */
/*   Updated: 2020/12/24 16:31:39 by tnakamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sysexits.h>

/*
** code 2 => incorrect builtin usage. (invalid options or missing arguments)
*/
# define EXIT_USAGE 2
# define EXIT_PERMIT 126
# define EXIT_NOT_CMD 127
# define EXIT_INVALID 128
# define EXIT_RANGE 255

# define NUMERIC_ARG "numeric argument required"
# define MANY_ARG "too many arguments"
# define INVAILD_ARG "not a valid identifier"
# define NOT_COMMAND "command not found"
# define IS_DIR "is a directory"

#endif
