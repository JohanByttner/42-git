/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_load_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 20:50:17 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/11 20:55:19 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sysexits.h>
#include "libmlxutil.h"
#include "fractol.h"

/*
** TODO: Logic for filling the screens initally
*/

int		fractol_load_images(void)
{
	t_fractol_config	*config;
	int					screen_count;

	screen_count = 0;
	config = fractol_get_config();
	if (config->render_mandelbrot)
		if (!(mlx_set_image(screen_count++, config->screen_width,
				config->screen_height)))
			fractol_exit(EX_SOFTWARE);
	if (config->render_julia)
		if (!(mlx_set_image(screen_count++, config->screen_width,
				config->screen_height)))
			fractol_exit(EX_SOFTWARE);
	return
		(screen_count);
}

