/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqnormal_plane.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:42:23 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/22 21:48:25 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_3dpoint	*mlx_eqnormal_plane(t_3dpoint *normal, t_3dplane *surface)
{
	t_3dpoint	v1;
	t_3dpoint	v2;

	mlx_eqsub_point(mlx_copy_point(&v1, surface->left), surface->centre);
	mlx_eqsub_point(mlx_copy_point(&v2, surface->right), surface->centre);
	return (mlx_eqcrossproduct_points(normal, &v1, &v2));
}
