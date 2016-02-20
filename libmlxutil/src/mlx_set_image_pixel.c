/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_image_pixel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:35:53 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:19:36 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include <mlx.h>
#include <limits.h>

void	mlx_set_image_pixel(t_mlx_image *im, t_colour *colour, size_t pixel)
{
	int				cval;
	int				j;
	char			*ptr;

	cval = mlx_get_colour_int(colour, im);
	j = im->bits_per_pixel;
	ptr = im->data + pixel;
	while (j > 0)
	{
		*ptr++ = (char)cval;
		cval = cval >> CHAR_BIT;
		j -= CHAR_BIT;
	}
}
