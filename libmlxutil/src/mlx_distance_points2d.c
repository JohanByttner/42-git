/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_distance_points2d.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:47:06 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/24 23:29:49 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libmlxutil.h"

double		mlx_distance_points2d(t_point *p1, t_point *p2)
{
	double	distance;

	distance = (p2->i - p1->i) * (p2->i - p1->i);
	distance += (p2->j - p1->j) * (p2->j - p1->j);
	return (sqrt(distance));
}
