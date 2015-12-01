# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2015/12/01 12:36:09 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
SRC=main.c
ROOTDIR=
LIBDIR=$(ROOTDIR)./
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
	$(CC) -o $(NAME) $(CFLAGS) -I$(INCDIR) $(SRC)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all
