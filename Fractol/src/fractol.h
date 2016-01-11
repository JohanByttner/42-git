/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 21:57:55 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/11 20:46:42 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MANDELBROT_COLOUR 5.0
# define JULIA_COLOUR 5.0
# include "libmlxutil.h"

/*
** This struct is zero-initialised on program start.
** Retrieve by calling fractol_get_config.
*/

typedef struct	s_fractol_config
{
	int			render_julia;
	t_colour	depth_julia;
	int			render_mandelbrot;
	t_colour	depth_mandelbrot;
	int			screen_width;
	int			screen_height;
}				t_fractol_config;

typedef struct	s_centre
{
	t_complex	centre;
	double		radius;
}				t_centre;

t_fractol_config		*fractol_get_config(void);

double					mandelbrot(t_complex *c);

double					julia(t_complex *z_val, t_complex *c);

void					fractol_put_mandelbrot_to_image(t_mlx_image *img,
				t_centre *centre, t_colour *depth);

void					fractol_put_julia_to_image(t_mlx_image *img,
				t_centre *centre, t_complex *c, t_colour *depth);

int						fractol_read_options(int ac, char **av);

int						fractol_load_screens(void);

void					fractol_exit(int exit_code);

#endif
