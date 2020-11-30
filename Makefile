# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtory <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 17:57:30 by rtory             #+#    #+#              #
#    Updated: 2019/11/11 17:57:45 by rtory            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
HEADER = fillit.h
FILES = parser.c main.c solve.c map.c validate.c shift.c
TARGET = $(FILES:%.c=%.o)
FLAGS = -Wall -Wextra -Werror

LIBFT = libft/

all : $(NAME)

$(NAME):
		make -C $(LIBFT)
		gcc $(FLAGS) -o $(NAME) $(FILES) -I $(HEADER) -L. libft/libft.a
clean:
	/bin/rm -f $(TARGET)
	make -C $(LIBFT) clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C $(LIBFT) fclean
re: fclean all
