/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 23:53:02 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/09 01:04:01 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libmlxutil.h"

double	mandelbrot(t_complex *c);

int		main(void)
{
	t_point		p;
	int			i;
	int			j;
	t_colour	colour;

	colour.blue = 0;
	colour.green = 0;
	mlx_set_window(0, 1000, 1000, "Mandelbrot");
	mlx_set_image(0, 1000, 1000);
	i = -500;
	j = -500;
	while (i++ < 500)
	{
		j = -500;
		while (j++ < 500)
		{
			p.i = i / 250.0;
			p.j = j / 250.0;
			colour.red = (unsigned char)( 5 * mandelbrot(&p));
			//printf("|%.3lf|", mandelbrot(&p));
			p.i = i;
			p.j = j;
			mlx_put_point2d_to_image(&p, mlx_get_image(0), &colour);
		}
	}
	mlx_put_image_to_window(mlx_get_handler()->init,
		mlx_get_window(0)->window, mlx_get_image(0)->image, 0, 0);
	usleep(10000000);
}
