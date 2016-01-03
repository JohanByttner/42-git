/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_rotate_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 02:51:44 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/03 19:35:20 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

static void		mlx_camera_rotate_camera(double *vin, double *vout,
					t_fmatrix *rot)
{
	t_fmatrix	tmpin;
	t_fmatrix	tmpout;

	tmpin.width = 3;
	tmpin.height = 3;
	tmpin.value = vin;
	tmpout.width = 3;
	tmpout.height = 3;
	tmpout.value = vout;
	mlx_eqmul_fmatrix(&tmpout, rot, &tmpin);
}

t_mlx_camera	*mlx_rotate_camera(t_mlx_camera *camera, t_fmatrix *rot)
{
	double		vin[9];
	double		vout[9];
	int			i;

	i = 0;
	while (i < 9)
	{
		vin[i] = camera->ext_matrix->value[i + (i / 3)];
		i++;
	}
	mlx_camera_rotate_camera(vin, vout, rot);
	i = 0;
	while (i < 9)
	{
		camera->ext_matrix->value[i + (i / 3)] = vout[i];
		i++;
	}
	return (camera);
}
