# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkaneko <kkaneko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/22 00:39:25 by kkaneko           #+#    #+#              #
#    Updated: 2022/06/05 01:35:14 by kkaneko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minitalk

CLIENT_NAME := client
SERVER_NAME := server
CLIENT_SRC := client_main.c
CLIENT_OBJS := $(CLIENT_SRC:.c=.o)
SERVER_SRC := server_main.c
SERVER_OBJS := $(SERVER_SRC:.c=.o)

LIBFT := libft.a
LIBFT_DIR := ./libft

INC_DIR := ./includes

CC := gcc
FLAGS := -Wall -Wextra -Werror

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) -o $@ $^ $(LIBFT_DIR)/$(LIBFT)

$(SERVER_NAME): $(SERVER_OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) -o $@ $^ $(LIBFT_DIR)/$(LIBFT)


.c.o:
	$(CC) $(FLAGS) -I $(INC_DIR) -c $^

all: $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	rm -f $(LIBFT_DIR)/$(LIBFT)
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: $(NAME) all clean fclean re
