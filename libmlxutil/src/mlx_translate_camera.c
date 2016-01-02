/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_translate_camera.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 02:18:38 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 03:19:08 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_mlx_camera	*mlx_translate_camera(t_mlx_camera *camera, t_3dpoint *t)
{
	camera->ext_matrix->value[3] += t->i;
	camera->ext_matrix->value[7] += t->j;
	camera->ext_matrix->value[11] += t->k;
	return (camera);
}
