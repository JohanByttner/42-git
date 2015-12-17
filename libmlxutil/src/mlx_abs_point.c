/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_abs_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 00:30:02 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/17 00:36:06 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libmlxutil.h"

double	mlx_abs_point(t_3dpoint *point)
{
	double	res;

	res = point->i * point->i;
	res += point->j * point->j;
	res += point->k * point->k;
	return (sqrt(res));
}
