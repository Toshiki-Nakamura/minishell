# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 14:19:48 by skohraku          #+#    #+#              #
#    Updated: 2020/12/06 17:55:10 by tnakamur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/main.c \
		srcs/prompt.c \
		srcs/cmd_manager.c \
		srcs/executor.c \
		srcs//builtin/cd.c \
		srcs//builtin/echo.c \
		srcs//builtin/env.c \
		srcs//builtin/execve.c \
		srcs//builtin/exit.c \
		srcs//builtin/export.c \
		srcs//builtin/pwd.c \
		srcs//builtin/unset.c \
		srcs/inout.c \
		srcs/env_list.c \
		srcs/env_info.c \
		srcs/utils.c \
		srcs/utils_string.c

NAME	= minishell
CC		= gcc
INCLUDE = -I./libft -I./includes
CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}
DEPS	= ${SRCS:.c=.d}
RM		= rm -f
LIBFT	= libft/libft.a

.c.o:
		${CC} ${CFLAGS} ${INCLUDE} -c -MMD -MP -MF ${<:.c=.d} $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${LIBFT}
		${CC} -o $@ $^

${LIBFT}:
		make -C libft bonus

all:	${NAME}

bonus:	${NAME}

-include $(DEPS)

clean:
		${RM} *.o *.d srcs/*.o srcs/*.d srcs/builtin/*.o srcs/builtin/*.d; make -C libft clean

fclean:	clean
		${RM} ${NAME} ${LIBFT}

re:	fclean all

.PHONY:		all clean fclean re

