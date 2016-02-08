/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_load_windows.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 20:26:23 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 13:42:00 by jbyttner         ###   ########.fr       */
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

static t_mlx_image  *fractol_load_window(int screen_count, char *window_name)
{
	t_fractol_config    *config;
	t_mlx_image         *im;

	config = fractol_get_config();
	if (!(mlx_set_window(screen_count, config->screen_width,
				config->screen_height, window_name)))
			fractol_exit(EX_UNAVAILABLE);
	else if (!(im = mlx_set_image(screen_count, config->screen_width,
				config->screen_height)))
			fractol_exit(EX_SOFTWARE);
	return (im);
}

static inline void	mandelbrot_load_window(int wd, t_fractol_config *config)
{
	if (wd)
	{
		im = fractol_load_window(wd, "Mandelbrot");
		fractol_put_mandelbrot_to_image(im, &(config->centre_mandelbrot),
				&(config->depth_mandelbrot));
		fractol_render_mandelbrot(wd);
		mlx_key_hook(mlx_get_window(wd)->window,
				fractol_key_hook, 0);
		mlx_mouse_hook(mlx_get_window(wd)->window,
				fractol_mouse_hook_mandelbrot, 0);
	}
}

static inline void julia_load_window(int wd, t_fractol_config *config)


int		fractol_load_windows(void)
{
	t_fractol_config	*config;
	t_mlx_image         *im;

	config = fractol_get_config();
	if (config->render_mandelbrot)
	{
		fractol_load_window(config->render_mandelbrot - 1, "Mandelbrot");
	if (config->render_julia)
		fractol_load_window(config->render_julia - 1, "Julia");
	if (config->render_burning_ship)
		fractol_load_window(config->render_burning_ship - 1,
				"Burning Ship");
	/*	{
		screen_count = config->render_ma
		im = fractol_load_window(config->render_mandelbrot - 1, "Mandelbrot");
		fractol_put_mandelbrot_to_image(im, &(config->centre_mandelbrot),
				&(config->depth_mandelbrot));
		fractol_render_mandelbrot(screen_count - 1);
		mlx_key_hook(mlx_get_window(screen_count - 1)->window,
				fractol_key_hook, 0);
		mlx_mouse_hook(mlx_get_window(screen_count - 1)->window,
				fractol_mouse_hook_mandelbrot, 0);
	}*/
/*	if (config->render_julia)
	{
		im = fractol_load_window(screen_count++, "Julia");
		//fractol_put_julia_to_image(im, &(config->centre_julia),
		//		&(config->complex_julia), &(config->depth_julia));
		fractol_render_julia(screen_count - 1);
		mlx_hook(mlx_get_window(screen_count - 1)->window, XMOTIONNOTIFY,
				XPOINTERMOTIONMASK, fractol_mouse_hook_julia, 0);
		mlx_key_hook(mlx_get_window(screen_count - 1)->window, 
				fractol_key_hook, 0);
	}
	if (config->render_burning_ship)
	{
		im = fractol_load_window(screen_count++, "Burning Ship");
		fractol_render_burning_ship(screen_count - 1);
	}
	return (screen_count);*/
	return (1);
}
