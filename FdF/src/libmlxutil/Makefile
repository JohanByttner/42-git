# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2015/12/09 19:47:30 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libmlxutil.a
SRC=	mlx_get_handler.c		\
		mlx_get_window.c		\
		mlx_set_window.c
ROOTDIR=./
LIBDIR=$(ROOTDIR)
BINDIR=$(ROOTDIR)
INCDIR=$(ROOTDIR)includes/ -I libft/includes
BUILDDIR=$(ROOTDIR)
FTDIR=libft
DIR=./

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
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
