/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 14:19:09 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 17:01:22 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libmlxutil.h"

double	burning_ship(t_complex *c)
{
	t_complex	z;
	t_complex	tmp;
	int			iter_count;
	double		mu;

	ft_bzero(&z, sizeof(t_complex));
	iter_count = 0;
	while (iter_count < 100 && mlx_abs_point2d(&z) < 10)
	{
		mlx_copy_point2d(&tmp, &z);
		tmp.i = fabs(tmp.i);
		tmp.j = fabs(tmp.j);
		mlx_eqmul_complex(&z, &tmp, &tmp);
		mlx_eqadd_point2d(&z, c);
		iter_count++;
	}
	if (iter_count == 100)
		mu = 0;
	else
		mu = iter_count - log2(log(mlx_abs_point2d(&z))) / log(2);
	return (mu);
}
