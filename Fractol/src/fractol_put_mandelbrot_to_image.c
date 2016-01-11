/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_put_mandelbrot_to_image.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 14:35:19 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/11 00:41:07 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "fractol.h"

void	fractol_put_mandelbrot_to_image(t_mlx_image *im, t_centre *centre,
			t_colour *depth)
{
	t_point		p;
	t_complex	c;
	t_colour	colour;
	double		colour_value;

	colour.endian = depth->endian;
	p.i = -im->size_x / 2 - 1;
	while (p.i++ < im->size_x / 2)
	{
		c.i = (p.i / im->size_x) * centre->radius * 2 + centre->centre.i;
		p.j = -im->size_y / 2 - 1;
		while (p.j++ < im->size_y / 2)
		{
			c.j = (p.j / im->size_y) * centre->radius * 2 + centre->centre.j;
			colour_value = mandelbrot(&c);
			colour.red = (unsigned char)(colour_value * depth->red);
			colour.green = (unsigned char)(colour_value * depth->green);
			colour.blue = (unsigned char)(colour_value * depth->blue);
			mlx_put_point2d_to_image(&p, im, &colour);
		}
	}
}
