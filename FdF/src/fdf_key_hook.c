/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 17:44:18 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/03 20:05:31 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define XK_MISCELLANY 0
#define XK_LATIN1 0
#include <X11/keysymdef.h>
#include "fdf.h"

int	fdf_key_hook(int keycode, void *param)
{
	t_mlx_camera	*camera;
	t_3dpoint		p = { 0, 0, 0 };
	double			angle;

	//p.i = 0; p.j = 0; p.k = 0;
	if (!(camera = mlx_get_image(0)->world->camera))
		return (0);
	if (keycode == XK_a || keycode == XK_d)
	{
		p.i = (keycode == XK_a ? -FDF_MOVE_STEP : FDF_MOVE_STEP);
		mlx_translate_camera(camera, &p);
	}
	else if (keycode == XK_w || keycode == XK_s)
	{
		p.k = (keycode == XK_w ? FDF_MOVE_STEP : -FDF_MOVE_STEP);
		mlx_translate_camera(camera, &p);
	}
	else if (keycode == XK_q || keycode == XK_e)
	{
		angle = (keycode == XK_q ? -FDF_ANGLE_STEP : FDF_ANGLE_STEP);
		mlx_rotatei_camera(camera, angle);
	}
	else if (keycode == XK_Escape)
		fdf_exit(0 && param);
	fdf_render_frame();
	return (0);
}
