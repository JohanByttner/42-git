/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_julia.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:16:55 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/13 23:13:06 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

/*
** Note: does not check if render is legal
*/

static void	fractol_check_julia_render(void)
{
	t_fractol_config	*config;

	static
}

void	fractol_render_julia(int screen_count)
{
	t_fractol_config	*config;

	config = fractol_get_config();
	fractol_put_julia_to_image(mlx_get_image(screen_count), 
		&(config->centre_julia), &(config->complex_julia),
		&(config->depth_julia));
	mlx_put_image_to_window(mlx_get_handler()->init,
		mlx_get_window(screen_count)->window,
		mlx_get_image(screen_count)->image, 0, 0);
}
