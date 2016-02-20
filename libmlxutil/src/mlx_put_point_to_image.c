/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_point_to_image.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 17:14:20 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:45:27 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

void		mlx_put_point_to_image(t_3dpoint *p, t_mlx_camera *c,
				t_mlx_image *im, t_colour *colour)
{
	t_fmatrix		cameraview;
	double			cameraview_arr[4];
	t_3dpoint		out;

	cameraview.value = cameraview_arr;
	mlx_eqpoint_to_fmatrix(&cameraview, p);
	if ((mlx_eqpoint_to_cameraview(&cameraview, c)))
		if ((mlx_eqpoint_to_coneview(&cameraview, c)))
		{
			mlx_eqfmatrix_to_point(&out, &cameraview);
			mlx_render_point_to_image(&out, c, im, colour);
		}
}
