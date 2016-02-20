# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/02/20 17:26:59 by jbyttner         ###   ########.fr        #
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
		fdf_new_colour.c

ROOTDIR=./
LIBDIR=$(ROOTDIR)
BINDIR=$(ROOTDIR)
INCDIR=$(ROOTDIR)get_next_line/ -I libft -I libmlxutil/includes	\
					-I/usr/local/includes -I/usr/X11/includes
LDDIR= libft/ -L libmlxutil/ -lmlxutil -lm -lft
BUILDDIR=$(ROOTDIR)
DIR=./

LIBLX= -L/usr/local/lib -lmlx -lXext -lX11
LIBMAC= -L libmlxutil/minilibx_macos -lmlx -framework OpenGL -framework AppKit

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

compile:
	cp get_next_line/get_next_line.c .
	$(CC) $(CFLLAGS) -c -I$(INCDIR) $(SRC)

$(NAME):	libft libmlxutil compile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LDDIR)	\
		$(LIBMAC)

linux:		libft libmlxutil compile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LDDIR)	\
		$(LIBLX)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all
