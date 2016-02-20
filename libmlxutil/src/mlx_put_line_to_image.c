/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_line_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 00:29:35 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:47:04 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** The current implementation will refuse to render a line
** if either of the two points are illegal
*/

static t_3dpoint	*mlx_line_eqget_cameraview(t_3dpoint *res,
				t_3dpoint *input, t_mlx_camera *camera)
{
	t_fmatrix	point;
	double		point_value[4];
	t_fmatrix	tmp;
	double		tmp_value[3];

	point.value = point_value;
	tmp.value = tmp_value;
	mlx_eqpoint_to_fmatrix(&point, input);
	mlx_eqmul_fmatrix(&tmp, camera->ext_matrix, &point);
	mlx_eqmul_fmatrix(&point, camera->int_matrix, &tmp);
	mlx_eqfmatrix_to_point(res, &point);
	return (res);
}

void				mlx_put_line_to_image(t_3dline *line, t_mlx_camera *c,
			t_mlx_image *im)
{
	t_3dline	l2;
	t_3dpoint	p1;
	t_3dpoint	p2;

	l2.start = mlx_line_eqget_cameraview(&p1, line->start, c);
	l2.end = mlx_line_eqget_cameraview(&p2, line->end, c);
	l2.colour = line->colour;
	l2.colour2 = line->colour2;
	if (!(mlx_eqget_line_cone_intersect(&l2)))
		return ;
	mlx_render_line_to_image(&l2, c, im);
}
