/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqget_cameraview.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 22:34:07 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/26 00:59:14 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** This function returns NULL if the point
** cannot be rendered. Any caller must handle
** such cases.
*/

t_fmatrix	*mlx_eqget_cameraview(t_fmatrix *point, t_mlx_camera *camera)
{
	t_fmatrix	tmp;
	double		darr[3];

	tmp.value = darr;
	mlx_eqmul_fmatrix(&tmp, camera->ext_matrix, point);
	if (tmp.value[2] <= camera->view_frustrum_start
			|| camera->view_frustrum_end < tmp.value[2])
		return (0);
	mlx_eqmul_fmatrix(point, camera->int_matrix, &tmp);
	return (point);
}
