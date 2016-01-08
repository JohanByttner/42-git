/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqget_line_cone_intersect.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:34:28 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/07 18:19:12 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include <math.h>

/*
** We will exclude lines based on whether they intersect the "view field"
** cone that surrounds the screen
** See http://www.geometrictools.com/Documentation/IntersectionLineCone.pdf
*/

t_3dline	*mlx_eqget_line_cone_intersect(t_3dline *line)
{
	t_fmatrix	transpose;
	double		transpose_arr[3];
	t_fmatrix	m;
	double		m_arr[9] = { -0.5, 0, 0, 0, -0.5, 0, 0, 0, 0.5 };
	t_fmatrix	unit;
	double		unit_arr[3];
	t_fmatrix	tmp;
	double		tmp_arr[3];
	t_3dpoint	u;
	double	c0;
	double	delta;
	double	c1;
	double	c2;
	double	t0;
	double	t1;

	transpose.value = transpose_arr;
	m.value = m_arr;
	m.width = 3;
	m.height = 3;
	//m_arr = { -0.5, 0, 0, 0, -0.5, 0, 0, 0, 0.5 };
	unit.value = unit_arr;
	tmp.value = tmp_arr;
	mlx_eqnormalize_point(mlx_eqsub_point(mlx_copy_point(&u, line->end), line->start));
	mlx_eqpoint_to_fmatrix(&unit, &u);

	mlx_eqtranspose_fmatrix(&transpose, &unit);
	mlx_eqmul_fmatrix(&tmp, &m, &unit);



	mlx_eqmul_fmatrix(&unit, &transpose, &tmp);

	c2 = unit.value[0];

	mlx_eqpoint_to_fmatrix(&unit, line->start);
	mlx_eqmul_fmatrix(&tmp, &m, &unit);
	mlx_eqmul_fmatrix(&unit, &transpose, &tmp);
	c1 = unit.value[0];

	mlx_eqpoint_to_fmatrix(&unit, line->start);
	mlx_eqtranspose_fmatrix(&transpose, &unit);
	mlx_eqmul_fmatrix(&tmp, &m, &unit);
	mlx_eqmul_fmatrix(&unit, &transpose, &tmp);
	c0 = unit.value[0];

	delta = c1 * c1 - c0 * c2;
	if (delta > 0 && c2 != 0)
	{
		t0 = (-c1 - sqrt(delta)) / c2;
		t1 = (-c1 + sqrt(delta)) / c2;
		c0 = fmin(t0, t1);
		c1 = fmax(t0, t1);
		c2 = mlx_distance_points(line->start, line->end);
		//c0 /= c2;
		//c1 /= c2;
		if (line->start->k * (1 - c0 / c2) + line->end->k * c0 / c2 > 0
			&& line->start->k * (1 - c1 / c2) + line->end->k * c1 / c2 > 0)
		{
			t0 = c0 < 0 ? 0 : c0;
			t1 = c1 > c2 ? c2 : c1;
			if (t0 > c2 || t1 < 0)
				return (0);
			t0 /= c2;
			t1 /= c2;
			//if (t0 > 1 || t1 < 0)
			//	return (0);
			//t0 = c0 < 0 ? 0 : c0;
			//t1 = c1 > 1 ? 1 : c1;
			/*if (t0 < t1)
			{
				if (t0 > 1 || t1 < 0)
					return (0);
				t0 = t0 < 0 ? 0 : t0;
				t1 = t1 > 1 ? 1 : t1;
			}
			else if (t0 > t1)
			{
				if (t1 > 1 || t0 < 0)
					return (0);
				t0 = t0 > 1 ? 1 : t0;
				t1 = t1 < 0 ? 0 : t1;
			}*/
			/*if (t0 == t1 || isnan(t0) || isnan(t1))
				return (0);
			//printf("|%lf|%lf|%d|%d|%d|\n", t0, t1, isnan(t0), isnan(t1), isnan(1.0));
			if (t0 > 0)
			{
				u.i  = (1 - t0) * line->start->i + t0 * line->end->i;
				u.j = (1 - t0) * line->start->j + t0 * line->end->j;
				u.k = (1 - t0) * line->start->k + t0 * line->end->k;
			}
			if (t1 < 1)
			{
				line->end->i = (1 - t1) * line->start->i + t1 * line->end->i;
				line->end->j = (1 - t1) * line->start->j + t1 * line->end->j;
				line->end->k = (1 - t1) * line->start->k + t1 * line->end->k;
			}
			if (t0 > 0)
			{
				line->start->i = u.i;
				line->start->j = u.j;
				line->start->k = u.k;
			}
			return (line);*/
		}
		else if (line->start->k * (1 - c0 / c2) + line->end->k * c0 / c2 > 0)
		{
			if (c0 < 0)
				return (0);
			t1 = c0 / c2;
			t0 = 0;
		}
		else if (line->start->k * (1 - c1 / c2) + line->end->k * c1 / c2 > 0)
		{
			if (c1 > c2)
				return (0);
			t0 = c1 / c2;
			t1 = 1;
		}
		else
			return (0);
		/*if (t0 < t1)
			{
				if (t0 > 1 || t1 < 0)
					return (0);
				t0 = t0 < 0 ? 0 : t0;
				t1 = t1 > 1 ? 1 : t1;
			}
			else if (t0 > t1)
			{
				if (t1 > 1 || t0 < 0)
					return (0);
				t0 = t0 > 1 ? 1 : t0;
				t1 = t1 < 0 ? 0 : t1;
		}*/
		if (t0 == t1 || isnan(t0) || isnan(t1))
				return (0);
			//printf("|%lf|%lf|%d|%d|%d|\n", t0, t1, isnan(t0), isnan(t1), isnan(1.0));
			if (t0 > 0)
			{
				u.i  = (1 - t0) * line->start->i + t0 * line->end->i;
				u.j = (1 - t0) * line->start->j + t0 * line->end->j;
				u.k = (1 - t0) * line->start->k + t0 * line->end->k;
			}
			if (t1 < 1)
			{
				line->end->i = (1 - t1) * line->start->i + t1 * line->end->i;
				line->end->j = (1 - t1) * line->start->j + t1 * line->end->j;
				line->end->k = (1 - t1) * line->start->k + t1 * line->end->k;
			}
			if (t0 > 0)
			{
				line->start->i = u.i;
				line->start->j = u.j;
				line->start->k = u.k;
			}
			//printf("|%lf|%lf|%lf|%lf|%lf|%lf|%lf|%lf|\n", line->start->i,
			//	line->start->j, line->start->k,
			//	line->end->i, line->end->j, line->end->k,
			//	t0, t1);
			return (line);

	}
	else
		return (0);
}
