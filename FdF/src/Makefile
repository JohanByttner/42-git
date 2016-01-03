# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/01/03 20:05:56 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRC=	main.c							\
		fdf_exit.c						\
		fdf_read_file.c					\
		get_next_line.c					\
		fdf_load_frame.c				\
		fdf_render_frame.c				\
		fdf_key_hook.c					\
		fdf_add_vertical_lines.c		\
		print_matrix.c


ROOTDIR=./
LIBDIR=$(ROOTDIR)
BINDIR=$(ROOTDIR)
INCDIR=$(ROOTDIR)get_next_line/
LDDIR= libft/ -L libmlxutil/ -L /usr/local/lib
BUILDDIR=$(ROOTDIR)
DIR=./

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -g# -Werror
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
	cp get_next_line/get_next_line.c .
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
