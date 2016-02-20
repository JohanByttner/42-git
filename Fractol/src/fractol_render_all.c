/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:54:03 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:16:14 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fractol_render_all(void *param)
{
	t_fractol_config	*config;
	int					screen_count;

	screen_count = 0;
	config = fractol_get_config();
	if (config->render_mandelbrot)
	{
		fractol_render_mandelbrot(config->render_mandelbrot - 1);
	}
	if (config->render_julia)
	{
		fractol_render_julia(config->render_julia - 1);
	}
	if (config->render_burning_ship)
		fractol_render_burning_ship(config->render_burning_ship - 1);
	return ((int)param);
}
