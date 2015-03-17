# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vame <vame@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 11:23:10 by vame              #+#    #+#              #
#    Updated: 2015/03/17 13:17:54 by vame             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INC = 	./push_swap.h

SRC =	./push_ope.c \
		./push_main.c \
		./push_sort.c \
		./push_pile.c \
		./push_tools.c \
		./push_sort2.c \
		./push_error.c \
		./push_do_ope.c \
		./push_check_in.c

BINAIRE = $(SRC:.c=.o)

TMP = $(INC:.h=.h.gch)

CFLAGS = -Werror -Wextra -Wall -I libft/includes/

all: $(NAME)

$(NAME): $(BINAIRE) $(INC)
		@make -C libft/
		gcc -c $(CFLAGS) $(INC) $(SRC)
		gcc -g -o $(NAME) $(BINAIRE) -lm -L libft/ -lft
		@rm -f $(TMP)

lib :
		@make -C libft/ fclean
		@make -C libft/

clean:
		rm -f $(BINAIRE)
		@make -C libft/ clean

fclean: clean
		rm -f $(NAME)
		@make -C libft/ fclean

re: fclean all

.PHONY: all lib clean fclean re
