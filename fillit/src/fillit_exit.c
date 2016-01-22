/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 20:39:46 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/21 21:21:53 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "fillit.h"

void	fillit_exit(int exit_code)
{
	ft_putnbr_fd(exit_code, 2);
	ft_putstr_fd(" Erreur\n", 2);
	exit(exit_code);
}
