/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_new_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:22:15 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 17:29:09 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

inline t_colour	*fdf_new_colour(t_3dpoint *point)
{
	t_colour	*colour;

	if (!(colour = mlx_new_colour(0, 0, 0, 0)))
		return (0);
	colour->red = (unsigned char)(fmin(255, -point->k));
	colour->green = (unsigned char)(fmin(255, -point->k * 15 + 100));
	colour->blue = (unsigned char)(fmin(255, -point->k * 1.2));
	return (colour);
}
