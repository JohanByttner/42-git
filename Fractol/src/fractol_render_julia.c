/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_julia.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:16:55 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:01:56 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	fractol_render_julia(int screen_count)
{
	t_fractol_config	*config;

	config = fractol_get_config();
	if (config->set_julia_render)
	{
		config->set_julia_render = 0;
		fractol_put_julia_to_image(mlx_get_image(screen_count), 
			&(config->centre_julia), &(config->complex_julia),
			&(config->depth_julia));
		mlx_put_image_to_window(mlx_get_handler()->init,
			mlx_get_window(screen_count)->window,
			mlx_get_image(screen_count)->image, 0, 0);
	}
}
