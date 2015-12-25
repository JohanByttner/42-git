/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqmul_fmatrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 01:08:28 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/24 00:15:49 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_fmatrix	*mlx_eqmul_fmatrix(t_fmatrix *res, t_fmatrix *a, t_fmatrix *b)
{
	size_t	row;
	size_t	col;
	size_t	i;
	size_t	off;

	row = 0;
	while (row < a->height)
	{
		col = 0;
		while (col < b->width)
		{
			off = b->width * row + col;
			res->value[off] = 0;
			i = 0;
			while (i < a->width)
			{
				res->value[off] += (a->value[a->width * row + i]
							* b->value[b->width * i + col]);
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
