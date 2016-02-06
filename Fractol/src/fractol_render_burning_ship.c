/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_burning_ship.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 14:34:48 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 14:37:37 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Note: does not check if render is legal
*/

/*static void	fractol_check_julia_render(void)
{
	t_fractol_config	*config;

	static
}*/

void	fractol_render_burning_ship(int screen_count)
{
	t_fractol_config	*config;

	config = fractol_get_config();
	fractol_put_burning_ship_to_image(mlx_get_image(screen_count), 
		&(config->centre_burning_ship), &(config->complex_burning_ship),
		&(config->depth_burning_ship));
	mlx_put_image_to_window(mlx_get_handler()->init,
		mlx_get_window(screen_count)->window,
		mlx_get_image(screen_count)->image, 0, 0);
}
