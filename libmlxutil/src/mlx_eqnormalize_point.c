/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqnormalize_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:01:54 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/06 14:52:24 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

/*
** Note: this function will (probably) break with really tiny vectors.
** Null vector is handled.
*/

t_3dpoint	*mlx_eqnormalize_point(t_3dpoint *point)
{
	double	absvalue;

	if ((absvalue = mlx_abs_point(point)))
	{
		point->i /= absvalue;
		point->j /= absvalue;
		point->k /= absvalue;
	}
	return (point);
}
