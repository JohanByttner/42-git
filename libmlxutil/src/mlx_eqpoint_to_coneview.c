/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqpoint_to_coneview.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 14:31:17 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 15:03:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

inline t_fmatrix	*mlx_eqpoint_to_coneview(t_fmatrix *point,
		t_mlx_camera *camera)
{
	if (camera->view_frustrum_start > point->value[2])
		return (0);
	point->value[0] *= ((double)camera->size_x / point->value[2]);
	point->value[1] *= ((double)camera->size_y / point->value[2]);
	return (point);
}
