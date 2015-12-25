/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqget_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 23:24:41 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/25 23:36:04 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_3dpoint	*mlx_eqget_point(t_3dpoint *res, t_3dpoint *input,
				t_mlx_camera *camera)
{
	t_fmatrix	point;
	double		point_value[4];

	point.value = point_value;

	mlx_eqpoint_to_fmatrix(&point, input);
	if (mlx_eqget_cameraview(&point, camera))
		if (mlx_eqget_coneview(&point, camera))
		{
			mlx_eqfmatrix_to_point(res, &point);
			return (res);
		}
	return (0);
}
