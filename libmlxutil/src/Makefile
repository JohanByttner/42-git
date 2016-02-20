# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/02/20 16:48:29 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libmlxutil.a
SRC=	mlx_get_handler.c				\
		mlx_get_window.c				\
		mlx_set_window.c				\
		mlx_set_image.c					\
		mlx_get_image.c					\
		mlx_render_image.c				\
		mlx_clear_image.c				\
		mlx_get_point.c					\
		mlx_cmp_points.c				\
		mlx_copy_point.c				\
		mlx_dup_point.c					\
		mlx_eqnormalize_point.c			\
		mlx_abs_point.c					\
		mlx_eqsub_point.c				\
		mlx_distance_points.c			\
		mlx_eqpoint_to_cameraview.c		\
		mlx_eqpoint_to_coneview.c		\
		mlx_eqpoint_to_point2d.c		\
		mlx_copy_point2d.c				\
		mlx_distance_points2d.c			\
		mlx_abs_point2d.c				\
		mlx_eqadd_point2d.c				\
		mlx_new_line.c					\
		mlx_set_line_colours.c			\
		mlx_render_lline.c				\
		mlx_renderl_lline.c				\
		mlx_new_world.c					\
		mlx_loadl_lline.c				\
		mlx_eqget_line_cone_intersect.c	\
		mlx_new_camera.c				\
		mlx_rotate_camera.c				\
		mlx_rotatei_camera.c			\
		mlx_rotatej_camera.c			\
		mlx_rotatek_camera.c			\
		mlx_translate_camera.c			\
		mlx_camera_record_pixel_depth.c	\
		mlx_new_fmatrix.c				\
		mlx_eqmul_fmatrix.c				\
		mlx_eqtranspose_fmatrix.c		\
		mlx_eqfmatrix_to_point2d.c		\
		mlx_eqfmatrix_to_point.c		\
		mlx_eqpoint_to_fmatrix.c		\
		mlx_put_point_to_image.c		\
		mlx_render_point_to_image.c		\
		mlx_put_point2d_to_image.c		\
		mlx_put_line_to_image.c			\
		mlx_render_line_to_image.c		\
		mlx_put_line2d_to_image.c		\
		mlx_set_image_pixel.c			\
		mlx_new_colour.c				\
		mlx_dup_colour.c				\
		mlx_copy_colour.c				\
		mlx_gradient_colours.c			\
		mlx_get_colour_int.c			\
		mlx_eqmul_complex.c

ROOTDIR=./
LIBDIR=$(ROOTDIR)
BINDIR=$(ROOTDIR)
INCDIR=$(ROOTDIR)includes/
BUILDDIR=$(ROOTDIR)
FTDIR=libft
DIR=./

OBJ=$(SRC:.c=.o)
ASM=$(SRC:.c=.s)
CC=gcc
CFLAGS=-c -O3 -fstrict-aliasing -g 
CWFLAGS=-Wall -Wextra -Wstrict-aliasing=2 #-Werror
AR=ar
ARFLAGS=rc
RM=rm -f

FT= -I $(FTDIR)
LIB= -I/usr/local/include

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(CWFLAGS) $(FT) -I$(INCDIR) $(SRC) $(LIB)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

asm:
	$(CC) -S -O3 -fstrict-aliasing -masm=intel $(CWFLAGS) $(FT) -I$(INCDIR) $(SRC)

clean:
	$(RM) $(OBJ) $(ASM)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all
