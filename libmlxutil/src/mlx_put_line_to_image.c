/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_line_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 00:29:35 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/26 11:49:01 by jbyttner         ###   ########.fr       */
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

static void		mlx_line_put_point_to_image(t_3dpoint *p, t_mlx_image *im,
			t_colour *colour, t_mlx_camera *camera)
{
	t_fmatrix	matrix;
	double		darr[4];
	t_point		p2;

	matrix.value = darr;
	mlx_eqpoint_to_fmatrix(&matrix, p);
	if (mlx_eqget_coneview(&matrix, camera))
	{
		mlx_eqfmatrix_to_point2d(&p2, &matrix);
		mlx_put_point2d_to_image(&p2, im, colour);
	}
}

static void		mlx_line_put_line_to_image(t_3dline *line, t_mlx_image *im,
			t_mlx_camera *camera, t_colour *colour)
{
	double		distance;
	double		sinv;
	double		cosv;
	double		zv;

	distance = mlx_distance_points2d((t_point *)line->start,
			(t_point *)line->end);
	cosv = (line->end->i - line->start->i) / distance;
	sinv = (line->end->j - line->start->j) / distance;
	zv = (line->end->k - line->start->k) / distance;
	while (distance-- >= 0)
	{
		line->start->j += sinv;
		line->start->i += cosv;
		line->start->k += zv;
		mlx_line_put_point_to_image(line->start, im, colour, camera);
	}
}

void	mlx_put_line_to_image(t_3dline *line, t_mlx_camera *c,
			t_mlx_image *im, t_colour *colour)
{
	t_3dline	l2;
	t_3dpoint		p1;
	t_3dpoint		p2;

	l2.start = mlx_line_eqget_cameraview(&p1, line->start, c);
	l2.end = mlx_line_eqget_cameraview(&p2, line->end, c);
	mlx_line_put_line_to_image(&l2, im, c, colour);
}
