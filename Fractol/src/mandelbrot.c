/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 22:52:05 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/09 00:06:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libmlxutil.h"

/*
** Retrieved from
** http://linas.org/art-gallery/escape/escape.html
*/

double	mandelbrot(t_complex *c)
{
	t_complex	z = { 0, 0 };
	t_complex	tmp;
	int			iter_count;
	double		mu;

	while (iter_count < 100 && mlx_abs_point2d(&z) < 20)
	{
		mlx_copy_point2d(&tmp, &z);
		mlx_eqadd_point2d(mlx_eqmul_complex(&z, &tmp, &tmp), c);
		iter_count++;
	}
	mu = iter_count - (log(log(mlx_abs_point2d(&z)))) / log(2);
	return (mu);
}
