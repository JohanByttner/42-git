/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_crossproduct_points.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 10:56:46 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/17 11:10:07 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** a x b
** =
** | i  j  k |
** | a1 a2 a3|
** | b1 b2 b3|
*/

t_3dpoint	*mlx_crossproduct_points(t_3dpoint *a, t_3dpoint *b, t_3dpoint *n)
{
	t_3dpoint	*out;

	if (!(out = ft_memalloc(sizeof(t_3dpoint))))
		return (0);
	return (mlx_eqcrossproduct_points(out, a, b, n));
}
