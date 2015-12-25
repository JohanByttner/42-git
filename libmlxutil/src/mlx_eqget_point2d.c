/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqget_point2d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 22:31:08 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/25 16:15:18 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** All functions using this function need to handle null returns
*/

t_point		*mlx_eqget_point2d(t_point *res, t_3dpoint *input,
				t_mlx_camera *camera)
{
	t_fmatrix	m;
	double		m_value[3];
	t_fmatrix	orig;
	double		orig_value[4];

	m.value = m_value;
	orig.value = orig_value;
	mlx_eqpoint_to_fmatrix(&orig, input);
	mlx_eqmul_fmatrix(&m, camera->ext_matrix, &orig);
	if (m.value[2] <= camera->view_frustrum_start
			|| camera->view_frustrum_end < m.value[2])
		return (0);
	m.value[0] /= m.value[2];
	m.value[1] /= m.value[2];
	if (!(camera->overwriting_render))
		if (!(mlx_camera_record_pixel_depth(&m, camera)))
			return (0);
	mlx_eqmul_fmatrix(&orig, camera->int_matrix, &m);
	mlx_eqfmatrix_to_point2d(res, &orig);
	return (res);
}
