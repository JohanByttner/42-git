/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_hook_julia.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:47:21 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:09:45 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

/*
** Discovered this goodie in minilibx/test/main.c
** mlx_hook(win3, MotionNotify, PointerMotionMask, mouse_win3, 0);
** For prototype:
** int	mouse_win3(int x,int y, void *p);
*/

int		fractol_mouse_hook_julia(int i, int j, void *p)
{
	static t_complex	complex_julia_last;
	t_fractol_config	*config;

	config = fractol_get_config();
	config->complex_julia.j += (j - complex_julia_last.j) * FRACTOL_JULIA_CSCALE;
	complex_julia_last.j = j;
	config->complex_julia.i -= (i - complex_julia_last.i) * FRACTOL_JULIA_CSCALE;
	complex_julia_last.i = i;
	config->set_julia_render = 1;
	return ((int)p);
}
