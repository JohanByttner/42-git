/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_load_screens.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 20:26:23 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/11 20:51:16 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sysexits.h>
#include "libmlxutil.h"
#include "fractol.h"

int		fractol_load_screens(void)
{
	t_fractol_config	*config;
	int					screen_count;

	screen_count = 0;
	config = fractol_get_config();
	if (config->render_mandelbrot)
		if (!(mlx_set_window(screen_count++, config->screen_width,
				config->screen_height, "Mandelbrot")))
			fractol_exit(EX_UNAVAILABLE);
	if (config->render_julia)
		if (!(mlx_set_window(screen_count++, config->screen_width,
				config->screen_height, "Julia")))
			fractol_exit(EX_UNAVAILABLE);
	return (screen_count);
}
