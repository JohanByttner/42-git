/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_point_to_image.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 14:45:29 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 16:38:14 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** Checks depth and decides whether to render a point to the screen.
** The point has to be in the right orientation.
*/

inline void	mlx_render_point_to_image(t_3dpoint *point,
		t_mlx_camera *camera, t_mlx_image *im, t_colour *colour)
{
	t_point		out;

	if (camera->view_frustrum_start < point->k
			&& point->k < camera->view_frustrum_end)
	{
		if (!camera->overwriting_render)
			if (!(mlx_camera_record_pixel_depth(point, camera)))
				return ;
		mlx_eqpoint_to_point2d(&out, point);
		mlx_put_point2d_to_image(&out, im, colour);
	}
}
