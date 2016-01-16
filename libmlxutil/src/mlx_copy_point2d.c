/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_copy_point2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:55:05 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/16 18:27:38 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_point		*mlx_copy_point2d(t_point *restrict copy, t_point *restrict point)
{
	copy->i = point->i;
	copy->j = point->j;
	return (copy);
}
