/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:27:17 by tnakamur          #+#    #+#             */
/*   Updated: 2021/08/23 17:13:58 by tnakamur         ###   ########.fr       */
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

# define STDIN	0
# define STDOUT	1

# define NUMERIC_ARG "numeric argument required"
# define MANY_ARG "too many arguments"
# define INVAILD_ARG "not a valid identifier"
# define NOT_COMMAND "command not found"
# define IS_DIR "is a directory"
# define SYNTAX_ERROR "syntax error near unexpected token"
# define MINISHELL_ERROR "minishell error near unexpected token"
# define MALLOC_ERROR "malloc error! The application will be forced to close."
# define MINISHELL_ERROR_ARG "minishell error. no arguments are needed."

# define MINISHELL_INVALID_OPERATOR "&(){}*"
# define COMMAND_SEPARAT_SPACES " \t"
# define IS_NOT_REDIRECT_WORD "<>& |;"

# define PROMPT "\033[32mminishell$ \033[0m"

typedef enum	e_redirec_type {
	REDIRECT_INPUT,
	REDIRECT_OVERRIDE,
	REDIRECT_APPEND,
	REDIRECT_NUM,
}				t_redirect_type;

typedef struct	s_fd {
	int	input;
	int	output;
}				t_fd;

typedef struct	s_redirect {
	char			*mark;
	t_redirect_type	type;
}				t_redirect;

#endif
