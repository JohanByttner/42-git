/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_put_burning_ship_to_image.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 14:38:08 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 16:56:35 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void			fractol_put_burning_ship_to_image(t_mlx_image *im,
			t_centre *centre, t_complex *c, t_colour *depth)
{
	t_point		p;
	t_complex	z;
	t_colour	colour;
	double		colour_value;

	colour.endian = depth->endian;
	p.i = -im->size_x / 2 - 1;
	while (p.i++ < im->size_x / 2)
	{
		z.i = (p.i / im->size_x) * centre->radius * 2 + centre->centre.i;
		p.j = -im->size_y / 2 - 1;
		while (p.j++ < im->size_y / 2)
		{
			z.j = (p.j / im->size_y) * centre->radius * 2 + centre->centre.j;
			colour_value = burning_ship(&z);
			colour.blue = (unsigned char)(colour_value * depth->blue);
			colour.red = (unsigned char)(colour_value * depth->red);
			colour.green = (unsigned char)(colour_value * depth->green);
			mlx_put_point2d_to_image(&p, im, &colour);
		}
	}
}
