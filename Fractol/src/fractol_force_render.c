/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_force_render.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 21:26:26 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:27:34 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractol_force_render(void)
{
	t_fractol_config	*config;

	config = fractol_get_config();
	config->set_mandelbrot_render = 1;
	config->set_julia_render = 1;
	config->set_burning_ship_render = 1;
}
