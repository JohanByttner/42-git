/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_hook_mandelbrot.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:08:59 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 17:59:03 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#define LEFT_CLICK 1
#define RIGHT_CLICK 2

void	fractol_mouse_hook_mandelbrot(int button, int x, int y, void *param)
{
	t_fractol_config	*config;

	config = fractol_get_config();
	if (button == LEFT_CLICK)
		config->centre_mandelbrot.radius /= 2;
	else if (button == RIGHT_CLICK)
		config->centre_mandelbrot.radius *= 2;
	if (button == LEFT_CLICK || button == RIGHT_CLICK)
	{
		config->centre_mandelbrot.centre.i += (((double)x)
				- config->screen_width / 2) / config->screen_width
				* config->centre_mandelbrot.radius * 2;
		config->centre_mandelbrot.centre.j += (((double)y)
				- config->screen_height / 2) / config->screen_height
				* config->centre_mandelbrot.radius * 2;
	}
	fractol_render_mandelbrot(config->render_mandelbrot - 1);
}
