/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbuff_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:43:58 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/05 20:23:51 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putbuff.h"

/*
** Writes n characters into the given fd. The writing is buffered and
** will only take place once FT_PUTBUFF_SIZE characters are to be
** written to the file descriptor. To write instantly, pass the command
** FLUSH. Returns number of characters printed.
** Warning: The writer does not FLUSH automatically at the end of the program.
** Flushing an empty buffer is safe.
*/

size_t	ft_putnbuff_fd(int fd, char *str, t_putbuff_cmd cmd, size_t n)
{
	char	buff[FT_PUTNBUFF_SIZE + 1];
	size_t	i;
	size_t	j;
	size_t	num_printed;

	i = 0;
	j = 0;
	num_printed = 0;
	while (j < n)
	{
		buff[i++] = str[j++];
		if (i == FT_PUTNBUFF_SIZE)
		{
			buff[FT_PUTNBUFF_SIZE] = '\0';
			num_printed += ft_putbuff_fd(fd, buff, cmd);
			i = 0;
		}
	}
	if (i != 0)
	{
		buff[i] = '\0';
		num_printed += ft_putbuff_fd(fd, buff, cmd);
	}
	return (num_printed);
}
