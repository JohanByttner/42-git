/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:37:56 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/03 20:52:55 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# define FT_PUTBUFF_SIZE 1000
# define FT_PUTNBUFF_SIZE 100
# define FT_PRINTF_KEEP_BUFFER 0

enum	e_putbuff_cmd
{
	ERROR,
	STORE,
	FLUSH,
	DELETE
};

size_t	ft_putbuff(char *str, enum e_putbuff_cmd cmd);

size_t	ft_putnbuff(char *str, enum e_putbuff_cmd cmd, size_t n);

size_t	ft_putbuff_fd(int fd, char *str, enum e_putbuff_cmd cmd);

size_t	ft_putnbuff_fd(int fd, char *str, enum e_putbuff_cmd cmd, size_t n);

#endif
