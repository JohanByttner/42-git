/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 22:20:06 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/20 21:28:16 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		fractol_key_hook(int keycode, void *param)
{
	t_centre	*centre;

	centre = (t_centre *)param;
	if (keycode == XKC_ESCAPE)
		fractol_exit(0);
	else if (keycode == XKC_A)
		centre->centre.i -= FRACTOL_KEY_MOVE * centre->radius;
	else if (keycode == XKC_D)
		centre->centre.i += FRACTOL_KEY_MOVE * centre->radius;
	else if (keycode == XKC_W)
		centre->centre.j -= FRACTOL_KEY_MOVE * centre->radius;
	else if (keycode == XKC_S)
		centre->centre.j += FRACTOL_KEY_MOVE * centre->radius;
	else
		return (0);
	fractol_force_render();
	return ((int)param);
}
