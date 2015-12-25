/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_get_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 23:17:12 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/23 17:13:14 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libmlxutil.h"

t_3dpoint		*mlx_get_point(int i, int j, int k)
{
	t_3dpoint		*point;

	point = malloc(sizeof(t_point));
	point->i = i;
	point->j = j;
	point->k = k;
	return (point);
}
