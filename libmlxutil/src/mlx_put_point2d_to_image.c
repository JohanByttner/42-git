/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_point2d_to_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 17:21:22 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/23 22:00:08 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libmlxutil.h"
#include "libft.h"

/*
** NOTE: We are assuming that CHAR_BIT divides the number of bits in
** an integer. If that is not true, colour will be lost.
*/

void	mlx_put_point2d_to_image(t_point *pt, t_mlx_image *im,
			t_colour *colour)
{
	size_t			pixel;
	long			x;
	long			y;

	x = (im->size_x / 2) + (long)(pt->i + (pt->i >= 0 ? 0.5 : -0.5));
	y = (im->size_y / 2) + (long)(pt->j + (pt->j >= 0 ? 0.5 : -0.5));
	if ((0 <= x && x < im->size_x)
		&& (0 <= y && y < im->size_y))
	{
		pixel = ((x * im->bits_per_pixel / CHAR_BIT)
			+ (y * im->size_line));
		mlx_set_image_pixel(im, colour, pixel);
	}
}
