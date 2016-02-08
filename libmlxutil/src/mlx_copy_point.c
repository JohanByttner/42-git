/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_copy_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:11:01 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 13:21:41 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

inline t_3dpoint	*mlx_copy_point(t_3dpoint *copy, t_3dpoint *point)
{
	copy->i = point->i;
	copy->j = point->j;
	copy->k = point->k;
	return (copy);
}
