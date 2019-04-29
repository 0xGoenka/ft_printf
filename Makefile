# **************************************************************************** #
                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleclet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/08 16:28:13 by eleclet           #+#    #+#              #
#    Updated: 2019/04/29 19:00:10 by eleclet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.so

CC = gcc
CFLAGS = -Werror -Wall -Wextra

SRC = ft_printf.c 
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft/
	echo "$(NAME) build"
	$(CC) -shared -o $(NAME) $(OBJ)

%.o: %
	gcc -c $(CFLAGS)  $< libft/libft.a
clean : 
	rm -rf $(OBJ)
	make -C libft/ clean
fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean
re : fclean all


