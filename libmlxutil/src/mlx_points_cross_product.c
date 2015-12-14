/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_points_cross_product.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 13:40:53 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/14 23:54:10 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libmlxutil.h"

t_3dpoint	*mlx_point_cross_product(t_3dpoint *a, t_3dpoint *b, t_3dpoint *n)
{
	t_3dpoint	*out;

	if (!(out = ft_memalloc(sizeof(t_3dpoint))))
		return (0);
	out->i = n->i * (a->j * b->k - a->k * b->j);
	out->j = n->j * (a->i * b->k - a->k * b->j);
	out->k = n->k * (a->i * b->j - a->j * b->i);
	return (out);
}
