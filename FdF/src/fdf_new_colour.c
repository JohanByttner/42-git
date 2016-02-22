/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_new_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 17:22:15 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/22 19:42:45 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

inline t_colour	*fdf_new_colour(t_3dpoint *point)
{
	t_colour		*colour;
	t_fdf_config	*config;
	t_fdf_window	*window;

	config = fdf_get_config(0, 0);
	window = (config->windows[config->current]);
	if (!(colour = mlx_new_colour(0, 0, 0, 0)))
		return (0);
	colour->red = (unsigned char)(fmin(255,
				-point->k * window->red.mul + window->red.cnst));
	colour->green = (unsigned char)(fmin(255,
				-point->k * window->green.mul + window->green.cnst));
	colour->blue = (unsigned char)(fmin(255,
				-point->k * window->blue.mul + window->blue.cnst));
	return (colour);
}
