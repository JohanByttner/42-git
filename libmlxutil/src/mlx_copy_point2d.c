/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_copy_point2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:55:05 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 13:21:58 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

inline t_point	*mlx_copy_point2d(t_point *restrict copy,
		t_point *restrict point)
{
	copy->i = point->i;
	copy->j = point->j;
	return (copy);
}
