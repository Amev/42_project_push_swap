# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vame <vame@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 11:23:10 by vame              #+#    #+#              #
#    Updated: 2015/03/18 11:44:14 by vame             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# cibles prioritaire pour les regles sans dependances
.PHONY: all lib clean fclean re

# desactivation des regles implicites pour eviter la compilation automatique
.SUFFIXES:

#
## variables
#

NAME = push_swap

INCLUDEDIR = libft/includes/
INC = 	push_swap.h
SRC =	push_ope.c \
		push_main.c \
		push_sort.c \
		push_pile.c \
		push_tools.c \
		push_error.c \
		push_insert.c \
		push_do_ope.c \
		push_check_in.c \
		push_which_ope.c

BINAIRE = $(SRC:.c=.o)
TMP = $(INC:.h=.h.gch)

CC = gcc
CFLAGS = -g -O3 -Werror -Wextra -Wall
LDFLAGS = -lm -L libft/ -lft

#
## regles
#

all: lib $(NAME)
		@:

$(NAME): $(BINAIRE) $(INC)
		$(CC) -o $(NAME) $(BINAIRE) $(LDFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -I $(INCLUDEDIR) -c $^ -o $@

lib:
		@git submodule --quiet init
		@git submodule --quiet update
		@make -s -C libft/

cleanlib:
		@make -s -C libft/ fclean

relib: cleanlib lib

clean:
		@rm -f $(BINAIRE)
		@make -s -C libft/ clean

fclean: clean
		@rm -f $(NAME)
		@make -s -C libft/ fclean

re: fclean all
