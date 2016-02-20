/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqpoint_to_cameraview.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 17:14:09 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 14:29:43 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** This function returns NULL if the point
** cannot be rendered. Any caller must handle
** such cases.
** It is embedded in that it has to be called with a matrix,
** not an actual point. Your compiler will remind you of this.
*/

inline t_fmatrix	*mlx_eqpoint_to_cameraview(t_fmatrix *point,
		t_mlx_camera *camera)
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
