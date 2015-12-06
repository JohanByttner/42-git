/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbuff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 23:10:44 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/05 20:24:53 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTBUFF_H
# define FT_PUTBUFF_H
# define FT_PUTBUFF_SIZE 1000
# define FT_PUTNBUFF_SIZE 100
# include <string.h>

typedef enum	e_putbuff_cmd
{
	ERROR,
	STORE,
	FLUSH,
	DELETE
}				t_putbuff_cmd;

size_t	ft_putbuff(char *str, t_putbuff_cmd cmd);

size_t	ft_putnbuff(char *str, t_putbuff_cmd cmd, size_t n);

size_t	ft_putbuff_fd(int fd, char *str, t_putbuff_cmd cmd);

size_t	ft_putnbuff_fd(int fd, char *str, t_putbuff_cmd cmd, size_t n);

#endif
