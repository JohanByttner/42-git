# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/01/09 01:14:23 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
SRC=	main.c							\
		mandelbrot.c


ROOTDIR=./
LIBDIR=$(ROOTDIR)
BINDIR=$(ROOTDIR)
INCDIR=$(ROOTDIR)get_next_line/
LDDIR= libft/ -L libmlxutil/ -L /usr/local/lib
BUILDDIR=$(ROOTDIR)
DIR=./

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra# -g -pg# -Werror
AR=ar
ARFLAGS=rc
RM=rm -f

all:	$(NAME)

libft:
	make -C libft/ fclean
	make -C libft/

libmlxutil:
	make -C libmlxutil/ fclean
	make -C libmlxutil/

$(NAME):	libft libmlxutil
	$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC) -I/usr/local/include	\
		-I libmlxutil/includes -I libft/includes	\
		-I /usr/include/X11
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LDDIR)	\
		-lmlxutil -lft -lmlx -lXext -lX11 -lm

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all
