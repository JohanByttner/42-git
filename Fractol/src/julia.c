/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 17:09:55 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/11 00:42:17 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libmlxutil.h"

/*
** Retrieved from
** http://linas.org/art-gallery/escape/escape.html
*/

double	julia(t_complex *z_val, t_complex *c)
{
	t_complex	z;
	t_complex	tmp;
	int			iter_count;
	double		mu;

	mlx_copy_point2d(&z, z_val);
	iter_count = 0;
	while (iter_count < 100 && mlx_abs_point2d(&z) < 2.0)
	{
		mlx_copy_point2d(&tmp, &z);
		mlx_eqmul_complex(&z, &tmp, &tmp);
		mlx_eqadd_point2d(&z, c);
		iter_count++;
	}
	mu = iter_count - (log(log(mlx_abs_point2d(&z)))) / log(2);
	return (mu);
}
