/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_hook_burning_ship.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 20:11:31 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/22 20:12:50 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define LEFT_CLICK 1
#define RIGHT_CLICK 2

int		fractol_mouse_hook_burning_ship(int button,
		int x, int y, void *param)
{
	t_fractol_config	*config;
	double				adjust[2];

	config = fractol_get_config();
	if (button == LEFT_CLICK)
		config->centre_burning_ship.radius /= 2;
	else if (button == RIGHT_CLICK)
		config->centre_burning_ship.radius *= 2;
	adjust[0] =  (((double)x) - config->screen_width / 2) / config->screen_width
				* config->centre_burning_ship.radius * 2;
	adjust[1] =  (((double)y) - config->screen_height / 2) / config->screen_height
				* config->centre_burning_ship.radius * 2;
	if (button == LEFT_CLICK)
	{
		config->centre_burning_ship.centre.i += adjust[0];
		config->centre_burning_ship.centre.j += adjust[1];
	}
	else if (button == RIGHT_CLICK)
	{
		config->centre_burning_ship.centre.i -= adjust[0] / 2;
		config->centre_burning_ship.centre.j -= adjust[1] / 2;
	}
	config->set_burning_ship_render = 1;
	return ((int)param);
}
