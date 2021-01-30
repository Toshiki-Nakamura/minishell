# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakamur <tnakamur@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/26 20:18:17 by tnakamur          #+#    #+#              #
#    Updated: 2020/06/27 14:17:38 by tnakamur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAG = gcc -Wall -Wextra -Werror

LIBS = ar -rc

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c\
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c\
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memset.c\
	ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c\
	ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c\
	ft_substr.c ft_putnbr_fd.c ft_putchar_fd.c ft_itoa.c ft_strjoin.c\
	ft_putendl_fd.c ft_putstr_fd.c ft_split.c ft_strtrim.c ft_strmapi.c\

BONUS = ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CFLAG) -c $< -o $@

$(NAME): $(OBJ)
	@$(LIBS) $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus: $(OBJ) $(OBJBONUS)
	@$(LIBS) $(NAME) $(OBJ) $(OBJBONUS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
