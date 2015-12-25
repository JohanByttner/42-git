/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqget_coneview.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 23:18:06 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/25 23:23:48 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_fmatrix	*mlx_eqget_coneview(t_fmatrix *point, t_mlx_camera *camera)
{
	point->value[0] /= point->value[2];
	point->value[1] /= point->value[2];
	if (!(camera->overwriting_render))
		if (!(mlx_camera_record_pixel_depth(point, camera)))
			return (0);
	return (point);
}
