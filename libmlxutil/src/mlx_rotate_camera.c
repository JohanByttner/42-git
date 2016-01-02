/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotate_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 02:51:44 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 03:15:15 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_mlx_camera	*mlx_rotate_camera(t_mlx_camera *camera, t_fmatrix *rot)
{
	t_fmatrix	tmp;
	double		arr[9];
	int			i;

	tmp.value = arr;
	camera->ext_matrix->width = 3;
	mlx_eqmul_fmatrix(&tmp, rot, camera->ext_matrix);
	i = 0;
	camera->ext_matrix->width = 4;
	while (i < 9)
	{
		camera->ext_matrix->value[i + (i % 3)] = arr[i];
		i++;
	}
	return (camera);
}
