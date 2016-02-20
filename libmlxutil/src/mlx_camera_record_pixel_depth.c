/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_camera_record_pixel_depth.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/25 15:46:01 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 15:09:01 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** Records the depth of the pixel's current rendering.
** A depth of 0 (depth of 0 being illegal for rendering)
** signifies that the pixel does not have an assigned depth and can be
** overwritten.
** To "lock" a pixel against overwriting, set it to the lowest possible
** float value, FLOAT_MIN in <stdlib.h>
*/

int		mlx_camera_record_pixel_depth(t_3dpoint *pt, t_mlx_camera *camera)
{
	size_t	pixel;
	double	x;
	double	y;

	x = (camera->size_x / 2) + (pt->i);
	x += (pt->i >= 0 ? 0.5 : -0.5);
	y = (camera->size_y / 2) + pt->j;
	y += (pt->j >= 0 ? 0.5 : -0.5);
	if (0 <= x && x < camera->size_x
			&& 0 <= y && y < camera->size_y)
	{
		pixel = camera->size_x * (int)y + (int)x;
		if (camera->pixel_render_depth[pixel] == 0
				|| camera->pixel_render_depth[pixel] > pt->k)
		{
			camera->pixel_render_depth[pixel] = pt->k;
			return (1);
		}
	}
	return (0);
}
