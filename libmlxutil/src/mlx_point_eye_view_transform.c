/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_point_eye_view_transform.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:37:27 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/17 22:18:26 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

static void mlx_scale_matrix(t_matrix_4x4 *matrix)
{

}

static void	mlx_point_eye_matrix(t_3dpoint *res, t_3dbasis *basis, t_3dpoint *p)
{
	t_matrix_4x4	matrix;

	matrix = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };
	mlx_put_point_to_matrix_4x4(matrix, &(basis->l), 0, 1);
	mlx_put_point_to_matrix_4x4(matrix, &(basis->m), 4, 1);
	mlx_put_point_to_matrix_4x4(matrix, &(basis->n), 8, 1);
	matrix[3] = mlx_dotproduct_points(&(basis->l, p));
	matrix[7] = mlx_dotproduct_points(&(basis->m), p);
	matrix[11] = mlx_dotproduct_points(&(basis->n), p);
	mlx_
}

t_3dpoint	*mlx_point_eye_view_transform(t_3dpoint *res, t_3dpoint *p,
				t_3dpoint *eye, t_3dpoint *up)
{
	t_3dbasis		basis;
	t_3dpoint		unit;

	basis = { 0 };
	unit = { 1, 1, 1 };
	basis.n = *(mlx_eqsub_point(mlx_copy_point(&(basis.m), eye), p));
	mlx_eqnormalize_point(&(basis.n));
	mlx_eqcrossproduct_points(&(basis.l), up, &(basis.n), &unit);
	mlx_eqnormalize_point(&(basis.l));
	mlx_eqcrossproduct_points(&(basis.m), &(basis.n), &(basis.l), &unit);
	mlx_eqnormalize_point(&(basis.m));

}
