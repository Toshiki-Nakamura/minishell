# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 14:19:48 by skohraku          #+#    #+#              #
#    Updated: 2020/11/26 14:48:12 by skohraku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= shell.c


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
		${RM} *.o *.d srcs/*.o srcs/*.d; make -C libft clean

fclean:	clean
		${RM} ${NAME} ${LIBFT}

re:	fclean all

.PHONY:		all clean fclean re

