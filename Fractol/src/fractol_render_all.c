/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_render_all.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:54:03 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/13 22:55:54 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_render_all(void)
{
	t_fractol_config	*config;
	int					screen_count;

	screen_count = 0;
	config = fractol_get_config();
	if (config->render_mandelbrot)
	{
		screen_count++;
	}
	if (config->render_julia)
	{
		fractol_render_julia(screen_count++);
	}
}
