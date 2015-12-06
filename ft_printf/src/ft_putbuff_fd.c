/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuff_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:36:44 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/05 20:24:02 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_putbuff.h"

/*
** Saves the string str to a buffer and writes it to fd after
** a certain number of characters have been read.
** WARNING: This function is not thread-safe and does not flush on exit.
** To properly use this function in multiple threads, define a thread-lock.
*/

size_t	ft_putbuff_fd(int fd, char *str, t_putbuff_cmd cmd)
{
	static char	buff[FT_PUTBUFF_SIZE];
	static int	buff_length = 0;
	size_t		num_printed;

	num_printed = 0;
	if (cmd == STORE && str != 0)
		while (*str != '\0')
		{
			if (buff_length == FT_PUTBUFF_SIZE)
			{
				write(fd, buff, FT_PUTBUFF_SIZE);
				buff_length = 0;
				num_printed += FT_PUTBUFF_SIZE;
			}
			buff[buff_length++] = *str++;
		}
	else if (cmd == FLUSH)
	{
		num_printed += buff_length;
		write(fd, buff, buff_length * sizeof(char));
		buff_length = 0;
	}
	else if (cmd == DELETE)
		buff_length = 0;
	return (num_printed);
}
