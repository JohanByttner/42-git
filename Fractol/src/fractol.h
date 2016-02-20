/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 21:57:55 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:27:51 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libmlxutil.h"
# include <math.h>
# include <mlx.h>
# define FRACTOL_JULIA_CSCALE 0.0017
# define JULIA_ITER_MAX 100
# define FRACTOL_KEY_MOVE 0.4

typedef struct	s_centre
{
	t_complex	centre;
	double		radius;
}				t_centre;

/*
** This struct is zero-initialised on program start.
** Retrieve by calling fractol_get_config.
*/

typedef struct	s_fractol_config
{
	int			render_julia;
	t_colour	depth_julia;
	t_centre	centre_julia;
	t_complex	complex_julia;
	int			set_julia_render;
	int			render_mandelbrot;
	t_colour	depth_mandelbrot;
	t_centre	centre_mandelbrot;
	int			set_mandelbrot_render;
	int			render_burning_ship;
	t_centre	centre_burning_ship;
	t_colour	depth_burning_ship;
	int			set_burning_ship_render;
	int			screen_width;
	int			screen_height;
}				t_fractol_config;

t_fractol_config		*fractol_get_config(void);

double					mandelbrot(t_complex *c);

double					julia(t_complex *z_val, t_complex *c);

double					burning_ship(t_complex *c);

void					fractol_put_mandelbrot_to_image(t_mlx_image *img,
				t_centre *centre, t_colour *depth);

void					fractol_put_julia_to_image(t_mlx_image *img,
				t_centre *centre, t_complex *c, t_colour *depth);

void					fractol_put_burning_ship_to_image(t_mlx_image *img,
				t_centre *centre, t_colour *depth);

int						fractol_read_options(int ac, char **av);

int						fractol_load_windows(void);

void					fractol_render_mandelbrot(int wd);

void					fractol_render_julia(int wd);

void					fractol_render_burning_ship(int wd);

int						fractol_mouse_hook_julia(int x, int y, void *param);

int						fractol_mouse_hook_mandelbrot(int button, int x, int y,
				void *param);

int						fractol_key_hook(int keycode, void *param);

int						fractol_render_all(void *param);

void					fractol_exit(int exit_code);

void					fractol_force_render(void);

#endif
