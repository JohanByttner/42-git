/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_line_to_image.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 00:29:35 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 20:45:13 by jbyttner         ###   ########.fr       */
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

inline double	mlx_line_get_distance(t_3dline *line)
{
	t_point	p1;
	t_point	p2;

	#define MLX_RENDER_DEPTH 1000.0
	if (line->start->k < - 1 || 1 < line->start->k)
	{
		p1.i = line->start->i * MLX_RENDER_DEPTH / line->start->k;
		p1.j = line->start->j * MLX_RENDER_DEPTH / line->start->k;
	}
	else
	{
		p1.i = line->start->i * MLX_RENDER_DEPTH;
		p1.j = line->start->j * MLX_RENDER_DEPTH;
	}
	if (line->end->k < -1 || 1 < line->end->k)
	{
		p2.i = line->end->i * MLX_RENDER_DEPTH / line->end->k;
		p2.j = line->end->j * MLX_RENDER_DEPTH / line->end->k;
	}
	else
	{
		p2.i = line->end->i * MLX_RENDER_DEPTH;
		p2.j = line->end->j * MLX_RENDER_DEPTH;
	}
	return (mlx_distance_points2d(&p1, &p2));
}

static void		mlx_line_put_line_to_image(t_3dline *line, t_mlx_image *im,
			t_mlx_camera *camera, t_colour *colour)
{
	double		distance;
	double		anglev[5];
	t_colour	cgradient[3];

	distance = mlx_line_get_distance(line);
	mlx_copy_colour(cgradient, line->colour);
	mlx_copy_colour(&cgradient[1], line->colour2);
	anglev[1] = (line->end->i - line->start->i) / distance;
	anglev[0] = (line->end->j - line->start->j) / distance;
	anglev[2] = (line->end->k - line->start->k) / distance;
	anglev[3] = 1.0 / distance;
	anglev[4] = 0;
	while (distance-- >= 0)
	{
		anglev[4] += anglev[3];
		mlx_gradient_colours(cgradient + 2, cgradient, cgradient + 1, anglev[4]);
		mlx_line_put_point_to_image(line->start, im, &cgradient[2], camera);
		line->start->j += anglev[0];
		line->start->i += anglev[1];
		line->start->k += anglev[2];
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
	l2.colour = line->colour;
	l2.colour2 = line->colour2;
	if (!(mlx_eqget_line_cone_intersect(&l2)))
		return ;
	mlx_line_put_line_to_image(&l2, im, c, colour);
}
