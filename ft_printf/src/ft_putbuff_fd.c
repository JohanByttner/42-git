/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuff_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:36:44 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/03 20:03:51 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

size_t	ft_putbuff_fd(int fd, char *str, enum e_putbuff_cmd cmd)
{
	static char	buff[FT_PRINTF_BUFF_SIZE];
	static int	buff_length = 0;
	size_t		num_printed;

	num_printed = 0;
	if (cmd == STORE && str != 0)
		while (*str != '\0')
		{
			if (buff_length == FT_PRINTF_BUFF_SIZE)
			{
				write(fd, buff, FT_PRINTF_BUFF_SIZE);
				buff_length = 0;
				num_printed += FT_PRINTF_BUFF_SIZE;
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
