# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2016/01/21 20:59:27 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
SRC=main.c					\
		fillit_read_file.c	\
		fillit_exit.c		\
		get_next_line.c
ROOTDIR=./
LIBDIR= libft/ -lft
BINDIR=$(ROOTDIR)./
INCDIR=$(ROOTDIR)libft/includes -IGet_Next_Line/
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
