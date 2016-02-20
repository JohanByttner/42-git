/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqmul_fmatrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 01:08:28 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 18:02:48 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

inline t_fmatrix	*mlx_eqmul_fmatrix(t_fmatrix *res,
		t_fmatrix *a, t_fmatrix *b)
{
	size_t	row;
	size_t	col;
	size_t	i;

	row = 0;
	while (row < a->height)
	{
		col = 0;
		while (col < b->width)
		{
			res->value[b->width * row + col] = 0;
			i = 0;
			while (i < a->width)
			{
				res->value[b->width * row + col] += a->value[a->width
					* row + i] * b->value[b->width * i + col];
				i++;
			}
			col++;
		}
		row++;
	}
	res->width = b->width;
	res->height = a->height;
	return (res);
}
