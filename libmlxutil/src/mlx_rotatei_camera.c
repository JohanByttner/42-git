/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotatei_camera.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 02:23:33 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/03 19:36:25 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libmlxutil.h"

t_mlx_camera	*mlx_rotatei_camera(t_mlx_camera *camera, double angle)
{
	t_fmatrix	tmp;
	double		arr[9];

	tmp.width = 3;
	tmp.height = 3;
	tmp.value = arr;
	ft_bzero(arr, sizeof(arr));
	arr[0] = 1;
	arr[4] = cos(angle);
	arr[5] = -sin(angle);
	arr[7] = sin(angle);
	arr[8] = cos(angle);
	return (mlx_rotate_camera(camera, &tmp));
}
