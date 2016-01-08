/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_distance_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:52:34 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/07 15:56:53 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libmlxutil.h"

double	mlx_distance_points(t_3dpoint *p1, t_3dpoint *p2)
{
	double	distance;
	double	tmp;

	tmp = (p2->i - p1->i);
	distance = tmp * tmp;
	tmp = (p2->j - p1->j);
	distance += tmp * tmp;
	tmp = (p2->k - p1->k);
	distance += tmp * tmp;
	return (sqrt(distance));
}
