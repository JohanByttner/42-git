/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqget_line_cone_intersect.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 21:34:28 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:43:21 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"
#include <math.h>

/*
** We will exclude lines based on whether they intersect the "view field"
** cone that surrounds the screen
** See http://www.geometrictools.com/Documentation/IntersectionLineCone.pdf
*/

static inline void		mlx_eqget_line_cone_intersect_values(t_3dline *line,
		double *c)
{
	t_fmatrix	m_arr[4];
	double		*m_arr_arr;
	t_3dpoint	u;

	m_arr_arr = (double[20]){ -0.62, 0, 0, 0, -0.62, 0, 0, 0, 0.38, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0 };
	m_arr[0].width = 3;
	m_arr[0].height = 3;
	m_arr[0].value = m_arr_arr;
	m_arr[1].value = m_arr_arr + 9;
	m_arr[2].value = m_arr_arr + 9 + 4;
	m_arr[3].value = m_arr_arr + 9 + 4 + 4;
	mlx_eqnormalize_point(mlx_eqsub_point(mlx_copy_point(&u, line->end),
				line->start));
	mlx_eqtranspose_fmatrix(&m_arr[2], (mlx_eqpoint_to_fmatrix(&m_arr[1], &u)));
	mlx_eqmul_fmatrix(&m_arr[3], &m_arr[0], &m_arr[1]);
	c[2] = mlx_eqmul_fmatrix(&m_arr[1], &m_arr[2], &m_arr[3])->value[0];
	mlx_eqpoint_to_fmatrix(&m_arr[1], line->start);
	mlx_eqmul_fmatrix(&m_arr[3], &m_arr[0], &m_arr[1]);
	c[1] = mlx_eqmul_fmatrix(&m_arr[1], &m_arr[2], &m_arr[3])->value[0];
	mlx_eqpoint_to_fmatrix(&m_arr[1], line->start);
	mlx_eqtranspose_fmatrix(&m_arr[2], &m_arr[1]);
	mlx_eqmul_fmatrix(&m_arr[3], &m_arr[0], &m_arr[1]);
	c[0] = mlx_eqmul_fmatrix(&m_arr[1], &m_arr[2], &m_arr[3])->value[0];
}

static inline t_3dline	*mlx_line_cone_sanity_checks(t_3dline *restrict line,
		double *restrict t)
{
	t_3dpoint	u;

	if (t[0] == t[1] || isnan(t[0]) || isnan(t[1]))
		return (0);
	if (t[0] > 0)
	{
		u.i = (1 - t[0]) * line->start->i + t[0] * line->end->i;
		u.j = (1 - t[0]) * line->start->j + t[0] * line->end->j;
		u.k = (1 - t[0]) * line->start->k + t[0] * line->end->k;
	}
	if (t[1] < 1)
	{
		line->end->i = (1 - t[1]) * line->start->i + t[1] * line->end->i;
		line->end->j = (1 - t[1]) * line->start->j + t[1] * line->end->j;
		line->end->k = (1 - t[1]) * line->start->k + t[1] * line->end->k;
	}
	if (t[0] > 0)
	{
		line->start->i = u.i;
		line->start->j = u.j;
		line->start->k = u.k;
	}
	return (line);
}

static inline t_3dline	*mlx_eqget_line_in_cone(t_3dline *restrict line,
		double *restrict c, double *restrict t)
{
	if (line->start->k * (1 - c[3]) + line->end->k * c[3] > 0
			&& line->start->k * (1 - c[4]) + line->end->k * c[4] > 0)
	{
		t[0] = c[0] < 0 ? 0 : c[0];
		t[1] = c[1] > c[2] ? c[2] : c[1];
		if (t[0] > c[2] || t[1] < 0)
			return (0);
		t[0] /= c[2];
		t[1] /= c[2];
	}
	else if (line->start->k * (1 - c[3]) + line->end->k * c[3] > 0
			&& !(c[3] < 0))
	{
		t[1] = c[3] > 1 ? 1 : c[3];
		t[0] = 0;
	}
	else if (line->start->k * (1 - c[4]) + line->end->k * c[4] > 0
			&& !(c[4] > 1))
	{
		t[0] = c[4] < 0 ? 0 : -c[4];
		t[1] = 5;
	}
	else
		return (0);
	return (mlx_line_cone_sanity_checks(line, t));
}

t_3dline				*mlx_eqget_line_cone_intersect(t_3dline *line)
{
	double		c[5];
	double		t[2];
	double		delta[2];

	mlx_eqget_line_cone_intersect_values(line, c);
	delta[0] = c[1] * c[1] - c[0] * c[2];
	if (delta[0] > 0 && c[2] != 0)
	{
		delta[1] = sqrt(delta[0]);
		t[0] = (-c[1] - delta[1]) / c[2];
		t[1] = (-c[1] + delta[1]) / c[2];
		c[0] = fmin(t[0], t[1]);
		c[1] = fmax(t[0], t[1]);
		c[2] = mlx_distance_points(line->start, line->end);
		c[3] = c[0] / c[2];
		c[4] = c[1] / c[2];
		return (mlx_eqget_line_in_cone(line, c, t));
	}
	else
		return (0);
}
