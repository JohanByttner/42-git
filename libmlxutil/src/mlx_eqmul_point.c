/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_eqmul_point.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:49:57 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/22 21:55:38 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_3dpoint	*mlx_eqmul_point(t_3dpoint *point, double mul)
{
	point->i *= mul;
	point->j *= mul;
	point->k *= mul;
	return (point);
}
