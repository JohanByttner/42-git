/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_load_windows.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 20:26:23 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:30:54 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sysexits.h>

#include <mlx.h>
#include "libmlxutil.h"
#include "fractol.h"

/*
** In case of error when opening the windows,
** we immediately exit.
*/

static t_mlx_image	*fractol_load_window(int screen_count,
		char *window_name, t_fractol_config *config)
{
	t_mlx_image         *im;

	if (!(mlx_set_window(screen_count, config->screen_width,
				config->screen_height, window_name)))
			fractol_exit(EX_UNAVAILABLE);
	if (!(im = mlx_set_image(screen_count, config->screen_width,
				config->screen_height)))
			fractol_exit(EX_SOFTWARE);
	return (im);
}

static inline void	mandelbrot_load_window(int wd, t_fractol_config *config)
{
	t_mlx_image		*im;

	im = fractol_load_window(wd, "Mandelbrot", config);
	fractol_put_mandelbrot_to_image(im, &(config->centre_mandelbrot),
			&(config->depth_mandelbrot));
	fractol_render_mandelbrot(wd);
	mlx_key_hook(mlx_get_window(wd)->window,
			fractol_key_hook, &(config->centre_mandelbrot));
	mlx_mouse_hook(mlx_get_window(wd)->window,
			fractol_mouse_hook_mandelbrot, 0);
}

static inline void	julia_load_window(int wd, t_fractol_config *config)
{
	t_mlx_image		*im;

	im = fractol_load_window(wd, "Julia", config);
	fractol_render_julia(wd);
	mlx_hook(mlx_get_window(wd)->window, XMOTIONNOTIFY,
			XPOINTERMOTIONMASK, fractol_mouse_hook_julia, 0);
	mlx_key_hook(mlx_get_window(wd)->window,
			fractol_key_hook, &(config->centre_julia));
}

static inline void	burning_ship_load_window(int wd, t_fractol_config *config)
{
	t_mlx_image		*im;

	im = fractol_load_window(wd, "Burning Ship", config);
	fractol_render_burning_ship(wd);
	mlx_key_hook(mlx_get_window(wd)->window,
			fractol_key_hook, &(config->centre_burning_ship));
}

int		fractol_load_windows(void)
{
	t_fractol_config	*config;

	config = fractol_get_config();
	if (config->render_mandelbrot)
		mandelbrot_load_window(config->render_mandelbrot - 1, config);
	if (config->render_julia)
		julia_load_window(config->render_julia - 1, config);
	if (config->render_burning_ship)
		burning_ship_load_window(config->render_burning_ship - 1, config);
	return (1);
}
