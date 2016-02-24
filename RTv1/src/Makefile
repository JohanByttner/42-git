# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/02/23 17:20:46 by jbyttner         ###   ########.fr        #
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
		fdf_new_colour.c				\
		fdf_get_config.c				\
		fdf_read_files.c

ROOTDIR=./
LIBDIR=$(ROOTDIR)
BINDIR=$(ROOTDIR)
INCDIR=$(ROOTDIR)get_next_line/ -I libft -I libmlxutil/includes	\
					-I/usr/local/includes -I/usr/X11/includes
LDDIR= libft/ -L libmlxutil/ -lmlxutil -lm -lft
BUILDDIR=$(ROOTDIR)
DIR=./

LIBLX= -L/usr/local/lib -lmlx -lXext -lX11
LIBMAC= -I libmlxutil/minilibx_macox/includes \
    -L libmlxutil/minilibx_macos -lmlx -framework OpenGL -framework AppKit

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror
AR=ar
ARFLAGS=rc
RM=rm -f

.PHONY: all libft libmlxutil linux clean fclean re

all:	libft libmlxutil $(NAME)

libft:
	make -C libft/

libmlxutil:
	make -C libmlxutil/


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(LDDIR)	\
		-I$(INCDIR) $(LIBMAC)

$(OBJ):
	$(CC) $(CFLLAGS) -c -I$(INCDIR) $(SRC)

linux:		libft libmlxutil compile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) \
		-I libft/includes -I libmlxutil/includes -L $(LDDIR)	\
		-I libmlxutil/minilibx_macos/includes \
		$(LIBLX)

clean:
	make -C libft/ clean
	make -C libmlxutil/ clean
	$(RM) $(OBJ)

fclean:	clean
	make -C libft/ fclean
	make -C libmlxutil/ fclean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all
