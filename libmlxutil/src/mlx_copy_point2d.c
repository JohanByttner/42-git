/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_copy_point2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:55:05 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/24 18:03:15 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlxutil.h"

t_point		*mlx_copy_point2d(t_point *copy, t_point *point)
{
	copy->i = point->i;
	copy->j = point->j;
	return (copy);
}
