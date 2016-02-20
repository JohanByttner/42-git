/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_dotproduct_points.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:36:35 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 18:04:32 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

double	mlx_dotproduct_points(t_3dpoint *a, t_3dpoint *b)
{
	double	value;

	value = a->i * b->i;
	value += a->j * b->j;
	value += a->k * b->k;
	return (value);
}
