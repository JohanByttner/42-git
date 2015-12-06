# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/21 16:00:38 by jbyttner          #+#    #+#              #
#    Updated: 2015/12/05 20:52:06 by jbyttner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRC=ft_printf.c				\
	ft_putbuff.c			\
	ft_putbuff_fd.c			\
	ft_putnbuff.c			\
	ft_putnbuff_fd.c		\
	ft_printf_format.c		\
	ft_printf_get_type.c
ROOTDIR=./
LIBDIR=$(ROOTDIR)./
BINDIR=$(ROOTDIR)./
INCDIR=$(ROOTDIR)includes/
BUILDDIR=$(ROOTDIR)./
DIR=./
FTDIR=$(ROOTDIR)libft/

OBJ=$(SRC:.c=.o)
CC=gcc
CFLAGS=-Wall -Wextra -Werror -ansi -c
AR=ar
ARFLAGS=rc
RM=rm -f

all:	$(NAME)

libft:
	make -C libft/ fclean
	make -C libft

$(NAME):
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(FTDIR)includes $(SRC)
	$(AR) $(ARFLAGS) $(LIBDIR)$(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIBDIR)$(NAME)

re: fclean all
