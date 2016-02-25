# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/02/25 21:14:33 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf
SRC=	rt_eqintersect_sphere.c					\
		rt_ray_trace.c			
	










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

SRC_PATH = ./srcs/

SRC =	$(addprefix $(SRC_PATH),$(SRC_NAME))
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
