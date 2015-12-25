/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_colour_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:29:33 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/25 17:52:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include <mlx.h>

/*
** TODO: Fix massive placeholder
*/

int		mlx_get_colour_int(t_colour *colour, t_mlx_image *im)
{
	int				val;
	unsigned char	*ptr;

	val = 0;
	ptr = (unsigned char *)(&val);
	*(ptr + (sizeof(int) - 1) - (sizeof(int) - 1) * im->endian) = colour->blue;
	*(ptr + (sizeof(int) - 2) - (sizeof(int) - 3) * im->endian) = colour->green;
	*(ptr + ((int)sizeof(int) - 3)
		- ((int)sizeof(int) - 5) * im->endian) = colour->red;
	return (mlx_get_color_value(mlx_get_handler()->init, val));
}
