# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 14:19:48 by skohraku          #+#    #+#              #
#    Updated: 2020/12/07 22:05:50 by skohraku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/main.c \
		srcs/prompt.c \
		srcs/cmd_manager.c \
		srcs/executor.c \
		srcs/builtin/cd.c \
		srcs/builtin/echo.c \
		srcs/builtin/env.c \
		srcs/builtin/execve.c \
		srcs/builtin/exit.c \
		srcs/builtin/export.c \
		srcs/builtin/pwd.c \
		srcs/builtin/unset.c \
		srcs/inout.c \
		srcs/env/env_info.c \
		srcs/env/env_list.c \
		srcs/env/env_list_base.c \
		srcs/utils/utils.c \
		srcs/utils/utils_string.c \
		srcs/utils/utils_list.c

NAME	= minishell
CC		= gcc
INCLUDE = -I./libft -I./includes

CFLAGS	= -Wall -Wextra -Werror

OBJS	= $(SRCS:.c=.o)
DEPS	= $(SRCS:.c=.d)
RM		= rm -f
LIBFT	= libft/libft.a

.c.o:
		$(CC) $(CFLAGS) $(INCLUDE) -c -MMD -MP -MF $(<:.c=.d) $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(LIBFT)
		$(CC) -o $@ $^

-include $(DEPS)

$(LIBFT):
		make -C libft bonus

all:	$(NAME)

bonus:	$(NAME)

clean:
		$(RM) $(OBJS) $(DEPS); make -C libft clean

fclean:	clean
		$(RM) $(NAME) $(LIBFT)

re:	fclean all

.PHONY:		all clean fclean re

