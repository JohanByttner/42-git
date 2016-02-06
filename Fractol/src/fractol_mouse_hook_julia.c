/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_mouse_hook_julia.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 21:47:21 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 14:01:28 by jbyttner         ###   ########.fr       */
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

void	fractol_mouse_hook_julia(int i, int j, void *p)
{
	static t_complex	complex_julia_last;
	static int counter  = 0;
	t_fractol_config	*config;

	printf("i was hit %d\n", counter++);
	config = fractol_get_config();
	config->complex_julia.j += (j - complex_julia_last.j) * FRACTOL_JULIA_CSCALE;
	complex_julia_last.j = j;
	config->complex_julia.i -= (i - complex_julia_last.i) * FRACTOL_JULIA_CSCALE;
	complex_julia_last.i = i;
//	if ((50 < config->screen_width - i && config->screen_width - i < 151)
//			&& (50 < j && j < 151))
	{
		printf("Re_rendering\n");
		fractol_render_julia(config->render_julia - 1);
	}
}
