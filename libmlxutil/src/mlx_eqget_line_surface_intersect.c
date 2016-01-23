/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqget_line_surface_intersect.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:27:18 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/22 22:20:10 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** From https://en.wikipedia.org/wiki/Line%E2%80%93plane_intersection
** If the line is parallel with the plane we return 0
*/

t_3dpoint	*mlx_eqget_line_surface_intersect(t_3dpoint *res,
				t_3dline *line, t_3dplane *surface)
{
	t_3dpoint	normal;
	double		d;
	double		tmp;

	mlx_eqnormal_plane(&normal, surface);
	mlx_eqsub_point(mlx_copy_point(res, surface->centre), line->start);
	d = mlx_dotproduct_points(res, &normal);
	tmp = mlx_dotproduct_points(line->end, &normal);
	if (!(tmp))
		return (0);
	d /= tmp;
	mlx_eqmul_point(mlx_copy_point(res, line->end), d);
	return (mlx_eqadd_point(res, line->start));
}
