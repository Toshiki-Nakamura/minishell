# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skohraku <skohraku@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 14:19:48 by skohraku          #+#    #+#              #
#    Updated: 2021/01/22 14:33:20 by skohraku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/main.c
#SRCS	= tests/main_quote.c
#SRCS	= tests/main_find_redirect.c
#SRCS	= tests/main_env.c
#SRCS	= tests/main_files.c

SRCS	+= srcs/builtin/cd.c \
		srcs/builtin/echo.c \
		srcs/builtin/env.c \
		srcs/builtin/execve.c \
		srcs/builtin/exit.c \
		srcs/builtin/export.c \
		srcs/builtin/pwd.c \
		srcs/builtin/unset.c \
		srcs/env/env_info.c \
		srcs/env/env_list.c \
		srcs/env/env_list_base.c \
		srcs/env/env_show.c \
		srcs/msutils/msutils_convert.c \
		srcs/msutils/msutils_env_list.c \
		srcs/msutils/msutils_env_param.c \
		srcs/msutils/msutils_redirect.c \
		srcs/msutils/msutils_syntax.c \
		srcs/utils/utils.c \
		srcs/utils/utils_is.c \
		srcs/utils/utils_string.c \
		srcs/utils/utils_string_operation.c \
		srcs/utils/utils_quote.c \
		srcs/utils/utils_list.c \
		srcs/utils/utils_split.c \
		srcs/utils/utils_stdlib.c \
		srcs/cmd_manager.c \
		srcs/executor.c \
		srcs/my_signal.c \
		srcs/pipe_executor.c \
		srcs/prompt.c \
		srcs/redirect.c \
		srcs/syntax_check.c

NAME	= minishell
CC		= gcc
INCLUDE = -I./libft -I./includes

CFLAGS	= -Wall -Wextra -Werror
ifeq ($(MAKECMDGOALS),test)
CFLAGS  += -D TEST
endif

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

test:	$(NAME)

bonus:	$(NAME)

clean:
		$(RM) $(OBJS) $(DEPS); make -C libft clean

fclean:	clean
		$(RM) $(NAME) $(LIBFT)

re:	fclean all

.PHONY:		all clean fclean re

