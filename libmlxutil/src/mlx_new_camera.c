/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_new_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:34:35 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 02:48:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <float.h>
#include "libmlxutil.h"

t_mlx_camera	*mlx_new_camera(int focus, int size_x, int size_y)
{
	t_mlx_camera	*camera;

	camera = malloc(sizeof(t_mlx_camera));
	camera->ext_matrix = mlx_new_fmatrix(4, 3);
	camera->ext_matrix->value[0] = 1;
	camera->ext_matrix->value[5] = 1;
	camera->ext_matrix->value[10] = 1;
	camera->int_matrix = mlx_new_fmatrix(3, 3);
	camera->int_matrix->value[0] = focus;
	camera->int_matrix->value[4] = focus;
	camera->int_matrix->value[8] = 1;
	camera->mode = MLX_DEFAULT_CAMERA_MODE;
	camera->view_frustrum_start = 0;
	camera->view_frustrum_end = DBL_MAX;
	camera->size_x = size_x;
	camera->size_y = size_y;
	camera->pixel_render_depth = ft_memalloc(sizeof(double) * size_x * size_y);
	camera->overwriting_render = 0;
	return (camera);
}
