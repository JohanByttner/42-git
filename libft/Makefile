# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2015/11/28 19:48:01 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft-test
SRC=main.c stringtests.c
ROOTDIR=./
LIBDIR=$(ROOTDIR)./
BINDIR=$(ROOTDIR)./
INCDIR=$(ROOTDIR)./
BUILDDIR=$(ROOTDIR)rendu/
TESTDIR=$(ROOTDIR)tests/
DIR=./

MAKE-LIBFT=make -C src/
Ilibft=-I src/includes/
Llibft=-L src/ -lft

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
AR=ar
ARFLAGS=rc
RM=rm -f

all:	$(NAME)

$(NAME):
	$(libft)
	$(CC) $(CFLAGS) $(Ilibft) -I$(INCDIR) $(SRC)
	$(CC) $(OBJ) -o $(NAME) $(Llibft) -lbsd

libft:
	$(MAKE-LIBFT) fclean
	$(MAKE-LIBFT)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all
