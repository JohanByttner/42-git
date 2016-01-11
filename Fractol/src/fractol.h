/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 21:57:55 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/11 00:39:56 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MANDELBROT_COLOUR 5.0
# define JULIA_COLOUR 5.0
# include "libmlxutil.h"

typedef struct	s_mlx_config
{
	t_colour	*julia_base;
}				t_mlx_config;

typedef struct	s_centre
{
	t_complex	centre;
	double		radius;
}				t_centre;

double			mandelbrot(t_complex *c);

double			julia(t_complex *z_val, t_complex *c);

void			fractol_put_mandelbrot_to_image(t_mlx_image *img, t_centre *centre,
					t_colour *depth);

void			fractol_put_julia_to_image(t_mlx_image *img, t_centre *centre,
					t_complex *c, t_colour *depth);

#endif
