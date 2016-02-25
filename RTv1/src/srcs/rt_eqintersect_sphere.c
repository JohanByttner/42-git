/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_eqintersect_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 19:18:06 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/25 21:15:22 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_3dpoint		*rt_eqintersect_sphere(t_3dpoint *res,
		const t_rtray *ray, const t_rtobj *obj)
{
	double		distance;
	double		quadratic;
	t_3dpoint	p;

	// TODO: Get nearest positive intersect
	mlx_eqsub_point(mlx_copy_point(&p, &ray->start), obj->obj.sphere->centre);
	distance = -mlx_dotproduct_points(&ray->end, &p)
	quadratic = mlx_sqabs_point(&p);
	quadratic += distance * distance;
	quadratic += obj->obj.sphere->radius * obj->obj.sphere->radius;
	if (quadratic <= 0)
		return (0);
	distance -= sqrt(quadratic);
	distance /= mlx_sqabs_point(&ray->end);
	mlx_eqsub_point(mlx_copy_point(&res, &ray->end), &ray->start);
	mlx_eqadd_point(mlx_eqmul_point(&res, distance), &ray->start);
	return (res);
}
