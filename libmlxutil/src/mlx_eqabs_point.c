/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqabs_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 00:30:02 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/15 22:56:15 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

double	mlx_eqabs_point(t_3dpoint *point)
{
	double	res;

	res = point->i * point->i;
	res += point->j * point->j;
	res += point->k * point->k;
	return (res);
}
