/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_mandelbrot.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:24:49 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 17:25:45 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

/*
** Note: does not check if render is legal
*/

/*static void	fractol_check_julia_render(void)
{
	t_fractol_config	*config;

	static
}*/

void	fractol_render_mandelbrot(int screen_count)
{
	t_fractol_config	*config;

	config = fractol_get_config();
	fractol_put_mandelbrot_to_image(mlx_get_image(screen_count), 
		&(config->centre_mandelbrot),
		&(config->depth_mandelbrot));
	mlx_put_image_to_window(mlx_get_handler()->init,
		mlx_get_window(screen_count)->window,
		mlx_get_image(screen_count)->image, 0, 0);
}
