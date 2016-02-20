/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_burning_ship.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 14:34:48 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:09:10 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_render_burning_ship(int screen_count)
{
	t_fractol_config	*config;

	config = fractol_get_config();
	if (config->set_burning_ship_render)
	{
		config->set_burning_ship_render = 0;
		fractol_put_burning_ship_to_image(mlx_get_image(screen_count), 
			&(config->centre_burning_ship),
			&(config->depth_burning_ship));
		mlx_put_image_to_window(mlx_get_handler()->init,
			mlx_get_window(screen_count)->window,
			mlx_get_image(screen_count)->image, 0, 0);
	}
}
