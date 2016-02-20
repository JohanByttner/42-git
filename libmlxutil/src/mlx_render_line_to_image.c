/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_render_line_to_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 15:16:18 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:46:34 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include <math.h>

static inline void	mlx_render_line_coneview(t_3dpoint *p1, t_3dpoint *p2,
		t_3dline *line, t_mlx_camera *camera)
{
	t_fmatrix	tmp;
	double		tmp_arr[4];

	tmp.value = tmp_arr;
	mlx_eqpoint_to_coneview(mlx_eqpoint_to_fmatrix(&tmp, line->start), camera);
	mlx_eqfmatrix_to_point(p1, &tmp);
	mlx_eqpoint_to_coneview(mlx_eqpoint_to_fmatrix(&tmp, line->end), camera);
	mlx_eqfmatrix_to_point(p2, &tmp);
}

inline void			mlx_render_line_to_image(t_3dline *line,
		t_mlx_camera *camera, t_mlx_image *im)
{
	t_3dpoint	points[2];
	double		distance;
	double		gradients[4];
	t_colour	colours[3];

	mlx_render_line_coneview(points, points + 1, line, camera);
	gradients[0] = points[1].i - points[0].i;
	gradients[1] = points[1].j - points[0].j;
	distance = sqrt(gradients[1] * gradients[1] + gradients[0] * gradients[0]);
	gradients[0] /= distance;
	gradients[1] /= distance;
	gradients[2] = (1.0 / distance);
	gradients[3] = 0;
	mlx_copy_colour(colours + 1, line->colour);
	mlx_copy_colour(colours + 2, line->colour2);
	while (distance-- >= 0)
	{
		mlx_gradient_colours(colours, colours + 1, colours + 2, gradients[3]);
		mlx_render_point_to_image(points, camera, im, colours);
		points->i += gradients[0];
		points->j += gradients[1];
		gradients[3] += gradients[2];
	}
}
