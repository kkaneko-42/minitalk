# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 17:44:55 by kkaneko           #+#    #+#              #
#    Updated: 2022/01/24 01:48:40 by kkaneko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCS := ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
		ft_tolower.c ft_strchr.c ft_strrchr.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_stradd.c\
		ft_putnbr_fd.c ft_isdigit.c ft_strncmp.c ft_printf.c \
		ft_putuint_base.c ft_putint.c ft_lstnew.c ft_lstadd_front.c \
		ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_free.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS := $(SRCS:.c=.o)
INCDIR := ../includes/
CC := gcc
FLAGS := -Wall -Wextra -Werror -I $(INCDIR)

$(NAME): $(OBJS)
	ar -rcs $@ $^

.c.o:
	$(CC) $(FLAGS) -c $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
