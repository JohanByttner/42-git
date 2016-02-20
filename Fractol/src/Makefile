# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/02/20 21:29:26 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol
SRC=	main.c								\
		mandelbrot.c						\
		julia.c								\
		burning_ship.c						\
		fractol_put_mandelbrot_to_image.c	\
		fractol_put_julia_to_image.c		\
		fractol_put_burning_ship_to_image.c	\
		fractol_get_config.c				\
		fractol_read_options.c				\
		fractol_load_windows.c				\
		fractol_render_mandelbrot.c			\
		fractol_render_julia.c				\
		fractol_render_burning_ship.c		\
		fractol_mouse_hook_mandelbrot.c		\
		fractol_mouse_hook_julia.c			\
		fractol_key_hook.c					\
		fractol_render_all.c				\
		fractol_exit.c						\
		fractol_force_render.c

ROOTDIR=./
LIBDIR=$(ROOTDIR)
BINDIR=$(ROOTDIR)
INCDIR=$(ROOTDIR)get_next_line/
LDDIR= libft/ -L libmlxutil/ -L /usr/local/lib
BUILDDIR=$(ROOTDIR)
DIR=./

LIBLX= -L/usr/local/lib -lXext -lX11
LIBMAC= -L libmlxutil/minilibx_macos -framework OpenGL -framework AppKit

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
		-I libmlxutil/includes -I libft	\
		-I /usr/include/X11
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LDDIR)	\
		-lmlxutil -lft -lmlx $(LIBMAC) -lm

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all
