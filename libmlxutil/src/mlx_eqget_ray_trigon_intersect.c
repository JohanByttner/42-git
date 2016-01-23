/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqget_ray_trigon_intersect.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 16:01:28 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/23 17:13:32 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

static int	mlx_ray_trigon_calculate_dotproduct(t_3dpoint *v0,
				t_3dpoint *v1, t_3dpoint *v2)
{
	double		dot[5];
	double		u;
	double		v;
	double		div;

	dot[0] = mlx_dotproduct_points(v0, v0);
	dot[1] = mlx_dotproduct_points(v0, v1);
	dot[2] = mlx_dotproduct_points(v0, v2);
	dot[3] = mlx_dotproduct_points(v1, v1);
	dot[4] = mlx_dotproduct_points(v1, v2);
	if (!(div = dot[0] * dot[3] - dot[1] * dot[1]))
		return (0);
	u = (dot[3] * dot[2] - dot[1] * dot[4]) / div;
	v = (dot[0] * dot[4] - dot[1] * dot[2]) / div;
	if (0 < u && 0 < v && u + v < 1)
		return (1);
	else
		return (0);
}

static int	mlx_ray_trigon_calculate_vectors(t_3dpoint *res,
				t_3dtrigon *trigon)
{
	t_3dpoint	v0;
	t_3dpoint	v1;
	t_3dpoint	v2;

	mlx_eqsub_point(mlx_copy_point(&v2, res), trigon->centre);
	mlx_eqsub_point(mlx_copy_point(&v0, trigon->left), trigon->centre);
	mlx_eqsub_point(mlx_copy_point(&v1, trigon->right), trigon->centre);
	return (mlx_ray_trigon_calculate_dotproduct(&v0, &v1, &v2));
}

t_3dpoint	*mlx_eqget_ray_trigon_intersect(t_3dpoint *res,
				t_3dray *ray, t_3dtrigon *trigon)
{
	if (!(mlx_eqget_line_surface_intersect(res, ray, trigon)))
		return (0);
	if (!(mlx_ray_trigon_calculate_vectors(res, trigon)))
		return (0);
	if (ray->end->i && 0 <= (res->i - ray->start->i) / ray->end->i)
		;
	else if (ray->end->j && 0 <= (res->j - ray->start->j) / ray->end->j)
		;
	else if (ray->end->k && 0 <= (res->k - ray->start->k) / ray->end->k)
		;
	else
		return (0);
	return (res);
}
