/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 21:07:24 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/05 20:23:35 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_putbuff.h"

size_t	ft_putnbuff(char *str, t_putbuff_cmd cmd, size_t n)
{
	return (ft_putnbuff_fd(1, str, cmd, n));
}
