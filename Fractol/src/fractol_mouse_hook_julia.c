/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_hook_julia.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:47:21 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 17:49:08 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <time.h>

/*
** Discovered this goodie in minilibx/test/main.c
** mlx_hook(win3, MotionNotify, PointerMotionMask, mouse_win3, 0);
** For prototype:
** int	mouse_win3(int x,int y, void *p);
*/

void	fractol_mouse_hook_julia(int i, int j, void *p)
{
	static clock_t		past = 0;
	clock_t				current;
	static t_complex	complex_julia_last;
	t_fractol_config	*config;

	config = fractol_get_config();
	config->complex_julia.j += (j - complex_julia_last.j) * FRACTOL_JULIA_CSCALE;
	complex_julia_last.j = j;
	config->complex_julia.i -= (i - complex_julia_last.i) * FRACTOL_JULIA_CSCALE;
	complex_julia_last.i = i;
	current = clock();
	if (past + 10000 < current)
		fractol_render_julia(config->render_julia - 1);
}
