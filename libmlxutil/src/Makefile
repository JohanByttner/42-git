# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2015/12/25 23:32:17 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libmlxutil.a
SRC=	mlx_get_handler.c				\
		mlx_get_window.c				\
		mlx_set_window.c				\
		mlx_set_image.c					\
		mlx_get_point.c					\
		mlx_cmp_points.c				\
		mlx_copy_point2d.c				\
		mlx_distance_points2d.c			\
		mlx_new_camera.c				\
		mlx_camera_record_pixel_depth.c	\
		mlx_eqget_cameraview.c			\
		mlx_eqget_coneview.c			\
		mlx_new_fmatrix.c				\
		mlx_eqmul_fmatrix.c				\
		mlx_eqfmatrix_to_point2d.c		\
		mlx_eqfmatrix_to_point.c		\
		mlx_eqpoint_to_fmatrix.c		\
		mlx_eqget_point2d.c				\
		mlx_eqget_point.c				\
		mlx_put_point_to_image.c		\
		mlx_put_point2d_to_image.c		\
		mlx_put_line_to_image.c			\
		mlx_put_line2d_to_image.c		\
		mlx_set_image_pixel.c			\
		mlx_get_colour_int.c
ROOTDIR=./
LIBDIR=$(ROOTDIR)
BINDIR=$(ROOTDIR)
INCDIR=$(ROOTDIR)includes/ -I libft/includes
BUILDDIR=$(ROOTDIR)
FTDIR=libft
DIR=./

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -c -pg -Wstrict-aliasing=2 #-Werror -c -pg
AR=ar
ARFLAGS=rc
RM=rm -f

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) -L $(FTDIR) -I $(FTDIR)/includes \
	-I$(INCDIR) $(SRC) -lm -I/usr/local/include \
							-L/usr/local/lib -lmlx -lXext -lX11
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all
