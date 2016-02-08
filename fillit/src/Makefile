# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/02/08 17:26:56 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
SRC=								\
		fillit_read_file.c			\
		fillit_exit.c				\
		fillit_print_grid.c			\
		fillit_validate_figures.c	\
		fillit_check_grid_density.c	\
		fillit_find_space.c			\
		fillit_place_shape.c		\
		fillit_solve_grid.c			\
		get_next_line.c				\
		main.c

ROOTDIR=./
LIBDIR= libft/ -lft
BINDIR=$(ROOTDIR)./
INCDIR=$(ROOTDIR)libft -IGet_Next_Line/
BUILDDIR=$(ROOTDIR)./
DIR=

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rc
RM=rm -f

all:	$(NAME)

libft:
	make -C libft/ fclean
	make -C libft/

$(NAME):	libft
	$(CC) -c $(CFLAGS) -I$(INCDIR) $(SRC)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ) -L $(LIBDIR)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
