/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_load_frame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:13:46 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 18:04:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include "fdf.h"

void	fdf_load_frame(t_list *llist)
{
	t_mlx_image		*img;
	t_mlx_window	*window;
	t_mlx_camera	*camera;

	if (!(img = mlx_set_image(0, FDF_SCREEN_WIDTH, FDF_SCREEN_HEIGHT)))
		fdf_exit(-1);
	else if (!(window = mlx_set_window(0, FDF_SCREEN_WIDTH, FDF_SCREEN_HEIGHT,
			"FdF")))
		fdf_exit(-2);
	else if (!(camera = mlx_new_camera(FDF_CAMERA_FOCUS, FDF_SCREEN_WIDTH,
			FDF_SCREEN_HEIGHT)))
		fdf_exit(-3);
	else if (!(mlx_new_world(camera, img)))
		fdf_exit(-4);
	mlx_loadl_lline(img, llist);
}
