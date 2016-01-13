/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_hook_julia.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:47:21 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/13 23:13:09 by jbyttner         ###   ########.fr       */
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

void	fractol_mouse_hook_julia(int x, int y, void *p)
{
	t_fractol_config	*config;

	config = fractol_get_config();
	if ((x == 101) && (51 <= y && y <= 151))
			config->centre_julia.centre.j -= (y - 100) * FRACTOL_JULIA_CSCALE;
	else if ((y == 101) && (51 <= x && x <= 151))
	{
			config->centre_julia.centre.i -= (x - 100) * FRACTOL_JULIA_CSCALE;
		printf("%lf\n", config->centre_julia.centre.i);
	}
	else if ((50 < config->screen_width - x && config->screen_width - x < 151)
			&& (50 < y && y < 151))
	{
		printf("Re_rendering\n");
		fractol_render_julia(config->render_julia - 1);

	}
}
